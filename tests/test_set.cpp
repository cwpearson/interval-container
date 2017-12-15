//
// Created by pearson on 12/8/17.
//

#include "icl/interval_set.hpp"
#include "icl/interval.hpp"

int main(void) {
  {
  std::cerr << "run 1...\n";
  Interval<int> i0(0, 0);
  IntervalSet<Interval<int>> s0;
  assert(s0.size() == 0);
  assert(s0.end() == s0.find(i0));
  std::cerr << "pass 1\n\n";
  }
  {
  std::cerr << "run 2...\n";
  Interval<int> i0(1, 2), i1(0,1), i2(2,3);
  IntervalSet<Interval<int>> s;
  s.insert_join(i0);
  assert(s.end() == s.find(i1));
  assert(s.end() == s.find(i2));
  std::cerr << "pass 2\n\n";
  }

  {
  std::cerr << "run 3...\n";
  Interval<int> i0(1, 2), i1(1,3), i2(0, 2), i3(1,2), i4(0, 3);
  IntervalSet<Interval<int>> s;
  s.insert_join(i0);
  assert(s.end() != s.find(i1));
  assert(*s.find(i1) == i0);
  assert(s.end() != s.find(i2));
  assert(*s.find(i2) == i0);
  assert(s.end() != s.find(i3));
  assert(*s.find(i3) == i0);
  assert(s.end() != s.find(i4));
  assert(*s.find(i4) == i0);
  std::cerr << "pass 3\n\n";
  }

{  
  std::cerr << "run 4...\n";
  IntervalSet<Interval<int>> s;
  Interval<int> i0(2, 4), i1(1,3);
  Interval<int> i2(1,2), i3(4,5), i4(3,4);
  s.insert_join(i0);
  s.insert_join(i1);
  assert(s.size() == 1);
  assert(Interval<int>(1,4) == *s.find(i4));
  assert(Interval<int>(1,4) == *s.find(i2));
  assert(s.end() == s.find(i3));
  std::cerr << "pass 4\n\n";
}

{  
  std::cerr << "run 5...\n";
  IntervalSet<Interval<int>> s;
  Interval<int> i0(1,3), i1(3,5), i2(2,4);
  s.insert_join(i0);
  assert(s.size() == 1);
  assert(i0 == *s.find(i0));
  assert(i0 == *s.find(i2));
  assert(s.find(i0) == s.find(i2));
  assert(s.end() == s.find(i1));

  s.insert_join(i1);
  assert(s.size() == 2);
  assert(i0 == *s.find(i0));
  assert(i1 == *s.find(i1));
  assert(i0 == *s.find(i2) || i1 == *s.find(i2));

  auto ii = s.find(i0);
  auto jj = s.find(i1);
  assert(++ii == jj);

  s.insert_join(i2);
  assert(s.size() == 1);
  {
  Interval<int> expected(1,5);
  assert(expected == *s.find(i0));
  assert(expected == *s.find(i1));
  assert(expected == *s.find(i2));
  }
  std::cerr << "pass 5\n\n";
}
  

  {
  std::cerr << "run 6...\n";
  Interval<int> i0(1, 2), i1(0,1), i2(2,3);
  IntervalSet<Interval<int>> s;
  s.insert_join(i0);
  assert(s.erase(i0));
  assert(s.size() == 0);
  std::cerr << "pass 6\n\n";
  }

  {
  std::cerr << "run 7...\n";
  Interval<int> i0(1, 2), i1(1,19), i2(4,11);
  IntervalSet<Interval<int>> s;
  s.insert_join(i0);
  s.insert_join(i1);
  assert(s.erase(i2));
  assert(s.size() == 0);
  std::cerr << "pass 7\n\n";
  }
  
  {
  std::cerr << "run 7.5...\n";
  Interval<int> i1(1,19), i2(4,11);
  IntervalSet<Interval<int>> s;
  s.insert_join(i1);
  s.insert_join(i2);
  assert(s.size() == 1);
  assert(i1 == *s.find(Interval<int>(18,19)));
  std::cerr << "pass 7.5\n\n";
  }

  {
  std::cerr << "run 8...\n";
  Interval<int> i0(1, 2), i1(0,1), i2(2,3);
  IntervalSet<Interval<int>> s;
  s.insert_split(i0);
  assert(s.end() == s.find(i1));
  assert(s.end() == s.find(i2));
  std::cerr << "pass 8\n\n";
  }

  {
  std::cerr << "run 9...\n";
  Interval<int> i0(0, 1), i2(0,2);
  IntervalSet<Interval<int>> s;
  s.insert_split(i0);
  s.insert_split(i0);
  assert(s.size() == 1);

  s.insert_split(i2);
  assert(s.size() == 1);
  assert(i2 == *s.find(i2));
  assert(i2 == *s.find(i0));
  std::cerr << "pass 9\n\n";
  }

  {
  std::cerr << "run 10...\n";
  Interval<int> i0(0, 4), i1(1,2);
  IntervalSet<Interval<int>> s;
  s.insert_split(i0);
  s.insert_split(i1);
  assert(s.size() == 3);
  auto f = *s.find(Interval<int>(0,1));
  std::cerr << f.lower() << " " << f.upper() << "\n";
  assert(Interval<int>(0,1) == *s.find(Interval<int>(0,1)));

  // s.insert_split(i2);
  // assert(s.size() == 1);
  // assert(i2 == *s.find(i2));
  // assert(i2 == *s.find(i0));
  // std::cerr << "pass 9\n\n";
  }

}