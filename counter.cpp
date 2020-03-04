#include "counter.h"
#include <ostream>

namespace csis3700 {
  counter::counter() {
    count=0;
  }

  counter::counter(int initial_count) {
    count = initial_count;
  }
  
  void counter::increment(int amount) {
    count += amount;
  }


  int counter::get_count() const {
    return count;
  }

  std::ostream& operator<<(std::ostream& outs, counter c) {
    outs << "counter(" << c.get_count() << ")";
    return outs;
  }

  counter operator+(counter first, counter second) {
    return counter(first.get_count() + second.get_count());
  }

}
