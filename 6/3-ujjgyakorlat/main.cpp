#include "animals.hpp"
#include "animals.hpp"

#include <iostream>

#define CHECK_EQUAL(a, b) \
  { \
    const auto va = (a); \
    const auto vb = (b); \
    if (va != vb) \
    { \
      std::cerr \
        << "\n" __FILE__ ":" << __LINE__ << ": expected\n" \
        << "  " #a " == " #b "\n" \
        << "but\n" \
        << "  " << va << " != " << vb << "\n" \
        << "\n"; \
      return mark; \
    } \
  }

int test_code()
{
  int mark = 1;

/* 2

  dog d1(10);
  const dog d2(4);

  CHECK_EQUAL(d1.human_age(), 70);
  CHECK_EQUAL(d2.human_age(), 28);

  turtle t1(3);
  const turtle t2(5);

  CHECK_EQUAL(t1.human_age(), 36);
  CHECK_EQUAL(t2.human_age(), 60);

  mark = 2; */
  
/* 3
  
  animal* a1 = &d1;
  CHECK_EQUAL(a1->human_age(), d1.human_age());

  const animal* a2 = &t2;
  CHECK_EQUAL(a2->human_age(), t2.human_age());

  class test : public animal {
  public:
    explicit test(int& counter) : counter_(&counter) {}
    ~test() { ++*counter_; }
    int human_age() const { return 0; }
    animal *clone() const { return new test(*this); }
  private:
    int* counter_;
  };

  int destructed_times = 0;
  animal* a3 = new test(destructed_times);
  delete a3;

  CHECK_EQUAL(destructed_times, 1);

  mark = 3; */
  
/* 4 

  {
    animal_group g1;

    g1.add(d1);
    CHECK_EQUAL(g1.human_age(), d1.human_age());

    g1.add(t2);
    CHECK_EQUAL(g1.human_age(), d1.human_age() + t2.human_age());

    g1.add(test(destructed_times));
    CHECK_EQUAL(destructed_times, 2);
  }
  CHECK_EQUAL(destructed_times, 3);

  mark = 4; */
  
/* 5 
  
  animal *a4 = a1->clone();
  delete a4;

  animal_group g2;
  g2.add(d1);
  g2.add(d2);
  g2.add(test(destructed_times));

  animal_group g3(g2);

  CHECK_EQUAL(destructed_times, 4);
  g3 = g2;
  CHECK_EQUAL(destructed_times, 5);

  g2.add(g3);

  mark = 5; */

  return mark;
}

int main()
{
  const int mark = test_code();
  std::cout << "Your mark is " << mark << std::endl;
}
