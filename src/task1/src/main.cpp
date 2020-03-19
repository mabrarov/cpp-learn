#include <algorithm>
#include <iostream>

#if defined(WIN32)
#include <tchar.h>
#endif

#if defined(WIN32)
int _tmain() {
#else
int main() {
#endif
  int n, prev;
  int count = 0;
  int max = 0;
  while (true) {
    std::cin >> n;
    if (n == 0) {
      break;
    }
    if (0 == count) {
      count = 1;
      prev = n;
      continue;
    }
    if (n == prev) {
      ++count;
    } else {
      max = (std::max)(count, max);
      count = 1;
    }
    prev = n;
  }
  max = (std::max)(count, max);
  std::cout << max;
  return 0;
}
