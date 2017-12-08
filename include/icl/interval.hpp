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
  Interval(const T &lower, const T &upper) : lower_(lower), upper_(upper) {}

  const T &lower() const noexcept { return lower_; }
  const T &upper() const noexcept { return upper_; }
};

#endif //PROJECT_INTERVAL_HPP
