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
  int prev;
  int count = 0;
  int max = 0;
  while (true) {
    int n;
    std::cin >> n;
    if (0 == n) {
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
