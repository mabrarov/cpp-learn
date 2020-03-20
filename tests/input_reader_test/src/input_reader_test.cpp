#include <stdexcept>
#include <vector>
#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <input_reader.hpp>

namespace cpp_learn {
namespace input_reader {

TEST(istream_reader, no_lines) {
  std::stringstream stream("\n");
  ASSERT_EQ(0, istream_reader(stream)());
}

TEST(istream_reader, non_digit) {
  std::stringstream stream("abc\n");
  ASSERT_THROW(istream_reader(stream)(), std::exception);
}

TEST(istream_reader, second_line_has_non_digit) {
  std::stringstream stream("123\n34.56\n345\n");
  auto reader = istream_reader(stream);
  ASSERT_EQ(123, reader());
  ASSERT_THROW(reader(), std::exception);
}

TEST(istream_reader, valid_single_int) {
  std::stringstream stream("123\n");
  ASSERT_EQ(123, istream_reader(stream)());
}

TEST(istream_reader, valid_ints) {
  std::stringstream stream("123\n321\n345\n");
  auto reader = istream_reader(stream);
  std::vector<int> nums;
  nums.reserve(3);
  for (int i = 0; i < 3; ++i) {
    nums.push_back(reader());
  }
  ASSERT_THAT(nums, testing::ElementsAre(123, 321, 345));
}

}
}