#if defined(WIN32)
#include <tchar.h>
#endif

#include <stdexcept>
#include <cstdlib>
#include <iostream>
#include <istream_reader.hpp>
#include <task2_lib.hpp>

#if defined(WIN32)
int _tmain() {
#else
int main() {
#endif
  try {
    auto input = cpp_learn::input::istream_reader(std::cin);
    std::cout << cpp_learn::task2::solve(input);
    return EXIT_SUCCESS;
  } catch (const std::exception& e) {
    std::cerr << e.what();
  } catch (...) {
    std::cerr << "Unknown error happened";
  }
  return EXIT_FAILURE;
}
