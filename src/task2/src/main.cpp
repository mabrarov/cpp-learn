#if defined(WIN32)
#include <tchar.h>
#endif

#include <stdexcept>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <task2_lib.hpp>

#if defined(WIN32)
int _tmain() {
#else
int main() {
#endif
  try {
    std::function<int()> input_generator = []() {
      int n;
      std::cin >> n;
      return n;
    };
    std::cout << cpp_learn::task2::solve(input_generator);
    return EXIT_SUCCESS;
  } catch (const std::exception& e) {
    std::cerr << e.what();
  } catch (...) {
    std::cerr << "Unknown error happened";
  }
  return EXIT_FAILURE;
}
