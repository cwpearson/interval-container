//
// Created by pearson on 12/8/17.
//

#ifndef INTERVAL_CONTAINER_INTERVAL_SET_HPP
#define INTERVAL_CONTAINER_INTERVAL_SET_HPP

#include <utility>
#include <map>
#include <memory>
#include <algorithm>
#include <iostream>
#include <cassert>

typedef int Direction;

// INTERVAL must have ::type, type lower(), type upper();
template<typename INTERVAL, typename RECORD>
class IntervalSet {
  typedef INTERVAL key_type;
  typedef RECORD value_type;
  typedef size_t size_type;
  typedef std::shared_ptr<RECORD> ptr_type;
  typedef std::pair<typename INTERVAL::type, Direction> Endpoint;
  typedef std::map<Endpoint, ptr_type> map_type;

  class iterator {
  public:
    RECORD &operator*() {
      return *lb_;
    }

  private:
    typename map_type::iterator lb_;
    typename map_type::iterator ub_;
  };

private:
  map_type map_;

  static Endpoint make_lower(const typename INTERVAL::type &i) {
    return Endpoint(i, 1);
  }

    static Endpoint make_upper(const typename INTERVAL::type &i) {
    return Endpoint(i, -1);
  }

  // bool contains(const Endpoint &e) {
  //   const auto ub = std::upper_bound(map_.begin(), map_.end(), e); // <= e, or last



  //   const auto lb = std::lower_bound(map_.begin(), map_.end(), e); // >= e, or last

  //   if (ub != map_.end() && ub.second == 1) { // ub <= e exists
  //     if (lb != map_.end() && lb != e && lb.second == -1) { // lb > e exists
  //       return true;
  //     }
  //   }
  //   return false;
  // }

  typename map_type::iterator enclosed_by_lower(const Endpoint &e) {

    // assert(--map_.begin() == map_.end());

    std::cerr << "Looking for lower of " << e.first << "\n";

    auto containingLower = map_.lower_bound(e); // >= e, or last
    if (containingLower == map_.end()) {
      std::cerr << "no lb\n";
      return containingLower;
    }

    if (containingLower == map_.begin()) {
      std::cerr << "lb is first map element\n";
      return containingLower;
    }

    --containingLower;
    std::cerr << "found candidate " << containingLower->first.first << "\n";
    if (containingLower->first.second == -1) { // points away from e
      std::cerr << "candidate points in wrong dir " << containingLower->first.first << "\n";
      return map_.end();
    }

    return containingLower;
  }

public:
  size_t size() { assert(map_.size() % 2 == 0); return map_.size() / 2; }

  std::pair<iterator, bool> insert(const key_type &k, const value_type &v) {

    std::cerr << "Insert: current map:\n";
    int cnt = 0;
    for (const auto &i : map_) {
      std::cerr << i.first.first << "(" << i.first.second << ") ";
      if (cnt++ %2) std::cerr <<"\n";
    }

    const auto kUpperEnd = make_upper(k.upper());
    const auto kLowerEnd = make_lower(k.lower());

    // Find any interval that encloses our lower bound
    auto enclosingLowerI = enclosed_by_lower(kLowerEnd);
    if (map_.end() != enclosingLowerI) {

      // point that endpoint at the new value
      std::cerr << "Lower enclosed by [" << enclosingLowerI->first.first << ", ...]\n";
      *enclosingLowerI->second = v;

      // find the corresponding upper endpoint
      auto enclosingUpperI = ++enclosingLowerI;
      assert(enclosingUpperI != map_.end());
      if (kUpperEnd > enclosingUpperI->first) { // if the new endpoint is bigger, erase orginal
      auto tmp = enclosingUpperI->second;
      *tmp = v;
        map_.erase(enclosingUpperI);
        map_[kUpperEnd] = tmp;
      } else {
        *enclosingUpperI->second = v;
      }
    } else {
      std::cerr << "no overlapping interval\n";
      map_[kLowerEnd] = ptr_type(new RECORD(v));
      map_[kUpperEnd] = map_[kLowerEnd];
    }



    // Find any interval we entirely subsume and erase
    auto containedUpper = map_.lower_bound(kUpperEnd);
    auto containedLower = map_.upper_bound(kLowerEnd);
    if (containedLower != map_.end() && containedUpper != map_.end()) {
      if (containedLower->first != make_lower(k.lower()) && containedUpper->first != make_upper(k.upper())) {
        map_.erase(containedLower);
        map_.erase(containedUpper);
      }
    } 

}






iterator find(const value_type &val) {
  auto lb = val.lower();
  auto ub = val.upper();
}

size_type erase(const value_type &val) {

}

static Endpoint lower_endpoint(int64_t i) {
  return Endpoint(i, 1);
}
static Endpoint upper_endpoint(int64_t i) {
  return Endpoint(i, -1);
}
};

#endif //INTERVAL_CONTAINER_INTERVAL_SET_HPP
