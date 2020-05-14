#if defined(WIN32)
#include <tchar.h>
#endif

#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <oxbridge2camford_lib.hpp>

#if defined(WIN32)
int _tmain() {
#else
int main() {
#endif
  try {
    int test_number;
    std::cin >> test_number;
    if (test_number <= 1 || test_number >= 500) {
      throw std::invalid_argument("Number of test should be > 1 and < 500");
    }
    for (; test_number > 0; --test_number) {
      int average_oxbridge;
      std::cin >> average_oxbridge;
      if (average_oxbridge < 60 || test_number > 100) {
        throw std::invalid_argument("Average Oxbridge mark should be >= 60 and <= 100");
      }
      int items_number;
      std::cin >> items_number;
      if (items_number < 1 || items_number > 10) {
        throw std::invalid_argument("Number of Oxbridge marks should be >= 1 and <= 10");
      }
      std::cout
          << cpp_learn::oxbridge2camford::find_min_camford_sum(
              average_oxbridge, items_number) / 10.0 / items_number
          << ' '
          << cpp_learn::oxbridge2camford::find_max_camford_sum(
              average_oxbridge, items_number) / 10.0 / items_number
          << '\n';
    }
    std::cout << std::flush;
    return EXIT_SUCCESS;
  } catch (const std::exception& e) {
    std::cerr << e.what();
  } catch (...) {
    std::cerr << "Unknown error happened";
  }
  return EXIT_FAILURE;
}
