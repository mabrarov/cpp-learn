#include <stdexcept>
#include <string>
#include <algorithm>
#include <task2_lib.hpp>

int cpp_learn::task2::solve(std::function<int()>& input_generator) {
  int max_seven_mult = 0, max_non_seven_mult = 0;
  while (true) {
    auto n = input_generator();
    if (0 == n) {
      break;
    }
    if (n < 0) {
      throw std::invalid_argument(
          "Only non-negative integer numbers allowed, but got: "
              + std::to_string(n));
    }
    if (n % 7 != 0) {
      max_non_seven_mult = (std::max)(max_non_seven_mult, n);
    } else if (n % 49 != 0) {
      max_seven_mult = (std::max)(max_seven_mult, n);
    }
  }
  if (0 == max_seven_mult || 0 == max_non_seven_mult) {
    return 1;
  }
  return max_seven_mult * max_non_seven_mult;
}
