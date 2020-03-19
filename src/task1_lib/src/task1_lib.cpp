#include <algorithm>
#include <task1_lib.hpp>

int cpp_learn::task1::solve(std::function<int()>& input_generator) {
  int prev = 0;
  int count = 0;
  int max = 0;
  while (true) {
    const int n = input_generator();
    if (0 == n) {
      break;
    }
    if (n == prev) {
      ++count;
    } else {
      max = (std::max)(count, max);
      count = 1;
    }
    prev = n;
  }
  return (std::max)(count, max);
}
