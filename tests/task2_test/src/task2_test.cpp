#include <functional>
#include <stdexcept>
#include <gtest/gtest.h>
#include <task2_lib.hpp>

namespace cpp_learn {
namespace task2 {

std::function<int()> generator(int values[]) {
  return [n = 0, values]() mutable { return values[n++]; };
}

TEST(solve, no_items) {
  std::function<int()> input = []() { return 0; };
  ASSERT_EQ(1, solve(input));
}

TEST(solve, negative_item_throw) {
  int values[] = {2, -1, 0};
  auto input = generator(values);
  ASSERT_THROW(solve(input), std::exception);
}

TEST(solve, non_seven_mult_singe_item) {
  int values[] = {2, 0};
  auto input = generator(values);
  ASSERT_EQ(1, solve(input));
}

TEST(solve, seven_mult_singe_item) {
  int values[] = {14, 0};
  auto input = generator(values);
  ASSERT_EQ(1, solve(input));
}

TEST(solve, forty_nine_mult_singe_item) {
  int values[] = {48 * 3, 0};
  auto input = generator(values);
  ASSERT_EQ(1, solve(input));
}

TEST(solve, non_seven_mult_2_items) {
  int values[] = {2, 4, 0};
  auto input = generator(values);
  ASSERT_EQ(1, solve(input));
}

TEST(solve, seven_mult_2_items) {
  int values[] = {14, 21, 0};
  auto input = generator(values);
  ASSERT_EQ(1, solve(input));
}

TEST(solve, seven_mult_and_forty_nine_mult_2_items) {
  int values[] = {42, 49 * 3, 0};
  auto input = generator(values);
  ASSERT_EQ(1, solve(input));
}

TEST(solve, no_forty_nine_mult_items) {
  int values[] = {42, 21, 5, 7, 3, 0};
  auto input = generator(values);
  ASSERT_EQ(42 * 5, solve(input));
}

TEST(solve, forty_nine_mult_items) {
  int values[] = {42, 21, 5, 7, 3, 49 * 2, 57, 70, 0};
  auto input = generator(values);
  ASSERT_EQ(70 * 57, solve(input));
}

}
}