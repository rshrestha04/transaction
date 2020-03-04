#ifndef COUNTER_H_
#define COUNTER_H_
#include <ostream>

namespace csis3700 {
  class counter {
  private:
    int count;
  public:
    counter();
    counter(int initial_count);
    void increment(int amount=1);
    int get_count() const;
  };

  std::ostream& operator<<(std::ostream& outs, counter c);
  counter operator+(counter first, counter second);
}

#endif
