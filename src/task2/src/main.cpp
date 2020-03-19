#include <algorithm>
#include <cstdlib>
#include <iostream>

#if defined(WIN32)
#include <tchar.h>
#endif

#if defined(WIN32)
int _tmain() {
#else
int main() {
#endif
  int max_seven_mult = 0, max_non_seven_mult = 0;
  while (true) {
    int n;
    std::cin >> n;
    if (0 == n) {
      break;
    }
    if (n < 0) {
      std::cerr << "Only non-negative integer numbers allowed. Got: " << n << std::endl;
      return EXIT_FAILURE;
    }
    if (n % 7 != 0) {
      max_non_seven_mult = (std::max)(max_non_seven_mult, n);
    } else if (n % 49 != 0) {
      max_seven_mult = (std::max)(max_seven_mult, n);
    }
  }
  if (0 == max_seven_mult || 0 == max_non_seven_mult) {
    std::cout << 1;
  } else {
    std::cout << max_seven_mult * max_non_seven_mult;
  }
  return EXIT_SUCCESS;
}
