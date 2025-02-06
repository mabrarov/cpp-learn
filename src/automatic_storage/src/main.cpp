#if defined(WIN32)
#include <tchar.h>
#endif

#include <stdexcept>
#include <cstdlib>
#include <iostream>

#if defined(WIN32)
int _tmain() {
#else
int main() {
#endif
  try {
    int before, sum, after;
    std::cout
        << "&before=" << &before << std::endl
        << "&sum   =" << &sum    << std::endl
        << "&after =" << &after  << std::endl
        << "sizeof(int) =" << sizeof(int) << std::endl
        << "alignof(int)=" << alignof(int) << std::endl;
    return EXIT_SUCCESS;
  } catch (const std::exception& e) {
    std::cerr << e.what();
  } catch (...) {
    std::cerr << "Unknown error happened";
  }
  return EXIT_FAILURE;
}
