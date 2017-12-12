//
// Created by pearson on 12/8/17.
//

#include "icl/interval_map.hpp"
#include "icl/interval.hpp"

int main(void) {
  {
  std::cerr << "run 1...\n";
  Interval<int> i0(0, 0);
  IntervalMap<Interval<int>, double> s0;
  assert(s0.size() == 0);
  assert(s0.end() == s0.find(i0));
  std::cerr << "pass 1\n\n";
  }

  {
  std::cerr << "run 2...\n";
  Interval<int> i0(1, 2), i1(0,1), i2(2,3);
  IntervalMap<Interval<int>, double> s;
  s.insert(i0, 0);
  assert(s.end() == s.find(i1));
  assert(s.end() == s.find(i2));
  std::cerr << "pass 2\n\n";
  }

  {
  std::cerr << "run 3...\n";
  Interval<int> i0(1, 2), i1(1,3), i2(0, 2), i3(1,2), i4(0, 3);
  IntervalMap<Interval<int>, double> s;
  s.insert(i0, 0);
  assert(s.end() != s.find(i1));
  assert(*s.find(i1) == 0);
  assert(s.end() != s.find(i2));
  assert(*s.find(i2) == 0);
  assert(s.end() != s.find(i3));
  assert(*s.find(i3) == 0);
  assert(s.end() != s.find(i4));
  assert(*s.find(i4) == 0);
  std::cerr << "pass 3\n\n";
  }

{  
  std::cerr << "run 4...\n";
  IntervalMap<Interval<int>, double> s;
  Interval<int> i0(2, 4), i1(1,3);
  Interval<int> i2(1,2), i3(4,5), i4(3,4);
  s.insert(i0, 0);
  s.insert(i1, 1);
  assert(s.size() == 1);
  assert(1 == *s.find(i4));
  assert(1 == *s.find(i2));
  assert(s.end() == s.find(i3));
  std::cerr << "pass 4\n\n";
}

{  
  std::cerr << "run 5...\n";
  IntervalMap<Interval<int>, double> s;
  Interval<int> i0(1,3), i1(3,5), i2(2,4);
  s.insert(i0, 0);
  assert(s.size() == 1);
  assert(0 == *s.find(i0));
  assert(0 == *s.find(i2));
  assert(s.end() == s.find(i1));
  s.insert(i1, 1);
  assert(s.size() == 2);
  assert(0 == *s.find(i0));
  assert(1 == *s.find(i1));
  assert(0 == *s.find(i2) || 1 == *s.find(i2));

  auto ii = s.find(i0);
  auto jj = s.find(i1);
  assert(++ii == jj);

  s.insert(i2, 2);
  assert(s.size() == 1);
  assert(2 == *s.find(i0));
  assert(2 == *s.find(i1));
  assert(2 == *s.find(i2));
  std::cerr << "pass 5\n\n";
}

  {
  std::cerr << "run 6...\n";
  Interval<int> i0(1, 2), i1(0,1), i2(2,3);
  IntervalMap<Interval<int>, double> s;
  s.insert(i0, 0);
  assert(s.erase(i0));
  assert(s.size() == 0);
  std::cerr << "pass 6\n\n";
  }

  {
  std::cerr << "run 7...\n";
  Interval<int> i0(1, 2), i1(1,19), i2(4,11);
  IntervalMap<Interval<int>, double> s;
  s.insert(i0, 0);
  s.insert(i1, 9);
  assert(s.erase(i2));
  assert(s.size() == 0);
  std::cerr << "pass 7\n\n";
  }
}