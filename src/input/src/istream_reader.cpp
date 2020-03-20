#include <cctype>
#include <stdexcept>
#include <string>
#include <istream>
#include <istream_reader.hpp>

std::function<int()> cpp_learn::input::istream_reader(std::istream& istream) {
  return [&istream]() -> int {
    std::string line;
    std::getline(istream, line);
    if (line.empty()) {
      return 0;
    }
    for (const auto& c : line) {
      if (!std::isdigit(c)) {
        throw std::invalid_argument(
            std::string("Only digits are allowed, but got: ") + c);
      }
    }
    return std::stoi(line);
  };
}
