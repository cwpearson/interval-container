//
// Created by pearson on 12/8/17.
//

#ifndef PROJECT_INTERVAL_HPP
#define PROJECT_INTERVAL_HPP

template<typename T>
class Interval {
private:
  T lower_;
  T upper_;

public:
  typedef T pos_type;
  typedef T type;
  Interval(const T &lower, const T &upper) : lower_(lower), upper_(upper) {}

  const T &lower() const noexcept { return lower_; }
  const T &upper() const noexcept { return upper_; }
  void set_lower(const T &lower) {lower_ = lower; }
  void set_upper(const T &upper) {upper_ = upper; }

  // template <typename T>
  bool operator<(const Interval<T> &rhs) const noexcept {
    if (lower_ == rhs.lower_) {
      return upper_ < rhs.upper_;
    }
    return lower_ < rhs.lower_;
  }

  bool operator==(const Interval<T> &rhs) const noexcept {
    return lower_ == rhs.lower_ && upper_ == rhs.upper_;
  }
};

#endif //PROJECT_INTERVAL_HPP
