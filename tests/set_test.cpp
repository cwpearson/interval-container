//
// Created by pearson on 12/8/17.
//

#include "icl/interval_set.hpp"
#include "icl/interval.hpp"

int main(void) {
  Interval<int> i0(0, 1);
  Interval<int> i1(0, 2);
  IntervalSet<Interval<int>, double> s0;
  s0.insert(i0, 0);
  s0.insert(i0, 1);
  assert(s0.size() == 1);
  
  Interval<int> i2(2, 4);
  Interval<int> i3(1, 3);
  IntervalSet<Interval<int>, double> s1;
  s1.insert(i1, 1);
  assert(s1.size() == 1);
  s1.insert(i2, 2);
   assert(s1.size() == 2);
  s1.insert(i3, 3);
   assert(s1.size() == 1);

  Interval<int> i4(1,2);
  Interval<int> i5(0,3);
  IntervalSet<Interval<int>, double> s2;
  s2.insert(i4, 4);
  s2.insert(i5, 5);
}