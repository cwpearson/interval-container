//
// Created by pearson on 12/8/17.
//

#include "icl/interval_set.hpp"
#include "icl/interval.hpp"

int main(void) {
  {
  std::cerr << "run 1...\n";
  Interval<int> i0(0, 0);
  IntervalSet<Interval<int>, double> s0;
  assert(s0.size() == 0);
  assert(s0.end() == s0.find(i0));
  std::cerr << "pass 1\n";
  }

  {
  std::cerr << "run 2...\n";
  Interval<int> i0(1, 2), i1(0,1), i2(2,3);
  IntervalSet<Interval<int>, double> s;
  s.insert(i0, 0);
  assert(s.end() == s.find(i1));
  assert(s.end() == s.find(i2));
  std::cerr << "pass 2\n";
  }

  {
  std::cerr << "run 3...\n";
  Interval<int> i0(1, 2), i1(1,3), i2(0, 2), i3(1,2);
  IntervalSet<Interval<int>, double> s;
  s.insert(i0, 0);
  assert(s.end() != s.find(i1));
  assert(s.end() != s.find(i2));
  assert(s.end() != s.find(i3));
  std::cerr << "pass 3\n";
  }

/*
  s0.insert(i0, 0);
  assert(s0.size() == 1);
  assert(1 == *s0.find(i0));
  s0.insert(i0, 1);
  assert(s0.size() == 1);
  assert(2 == *s0.find(i1));
  
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
  */
}