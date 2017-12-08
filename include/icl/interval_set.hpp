//
// Created by pearson on 12/8/17.
//

#ifndef INTERVAL_CONTAINER_INTERVAL_SET_HPP
#define INTERVAL_CONTAINER_INTERVAL_SET_HPP

#include <utility>
#include <map>
#include <memory>
#include <algorithm>

typedef int Direction;

typedef std::pair<int, Direction> Endpoint;

template<typename INTERVAL_TYPE, typename RECORD_TYPE>
class IntervalSet {
  typedef INTERVAL_TYPE key_type;
  typedef RECORD_TYPE value_type;
  typedef size_t size_type;
  typedef std::shared_ptr<RECORD_TYPE> ptr_type;
  typedef std::map<Endpoint, ptr_type> map_type;

  class iterator {
  public:
    RECORD_TYPE &operator*() {
      return lb_->
    }

  private:
    typename map_type::iterator lb_;
    typename map_type::iterator ub_;
  };

private:
  map_type map_;

  bool contains(const Endpoint &e) {
    const auto ub = std::upper_bound(map_.begin(), map_.end(), e); // <= e, or last



    const auto lb = std::lower_bound(map_.begin(), map_.end(), e); // >= e, or last

    if (ub != map_.end() && ub.second == 1) { // ub <= e exists
      if (lb != map_.end() && lb != e && lb.second == --1) { // lb > e exists
        return true;
      }
    }
    return false;
  }

  std::pair<iterator, bool> insert(const key_type &k, const value_type &v) {

    const auto le = lower_endpoint(k.lower());
    const auto ub = std::upper_bound(map_.begin(), map_.end(), le); // <= le, or last

    const auto ue = upper_endpoint(k.upper());
    const auto lb = std::lower_bound(map_.begin(), map_.end(), ue); // >= ue, or last

    // Find the lower endpoint of any overlapping interval
    auto overlapLowerEnd = std::upper_bound(map_.begin(), map_.end(), le); // <= le, or last
    if (overlapLowerEnd != map_.end()) {
      if (overlapLowerEnd.second == -1) { // points away from le
        overlapLowerEnd = map_.end();
      }
    }

    // No existing interval is less than le


    overlapLowerEnd = std::lower_bound(map_.begin(), map_.end(), ue); // >= ue, or last
    if (overlapUpper == map_.end() || overlapLowerEnd)
  }

  if ((ub != map_.
  end() &&
  ub.second == 1) /* lte le, pointing to le */
  || (lb != map_.
  end() &&
  lb !=
  le &&lb
  .second == -1) /* gt le, pointing to le */) { // le is inside an interval

  } else { // no overlapping interval

  }

}

    iterator
find(const value_type &val) {
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
