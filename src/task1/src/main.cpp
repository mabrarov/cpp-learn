#if defined(WIN32)
#include <tchar.h>
#endif

#include <iostream>
#include <functional>
#include <task1_lib.hpp>

#if defined(WIN32)
int _tmain() {
#else
int main() {
#endif
  std::function<int()> input_generator = []() {
    int n;
    std::cin >> n;
    return n;
  };
  std::cout << cpp_learn::task1::solve(input_generator);
  return 0;
}
