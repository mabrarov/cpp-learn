#include <functional>
#include <gtest/gtest.h>
#include <task1_lib.hpp>

namespace cpp_learn {
namespace task1 {

std::function<int()> generator(int values[]) {
  int n = 0;
  return [n, values]() mutable { return values[n++]; };
}

TEST(solve, no_items) {
  std::function<int()> input = []() { return 0; };
  ASSERT_EQ(0, solve(input));
}

TEST(solve, singe_item) {
  int values[] = {1, 0};
  auto input = generator(values);
  ASSERT_EQ(1, solve(input));
}

TEST(solve, equal_sequences_of_items) {
  int values[] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 0};
  auto input = generator(values);
  ASSERT_EQ(3, solve(input));
}

TEST(solve, max_sequence_at_the_begining) {
  int values[] = {1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 0};
  auto input = generator(values);
  ASSERT_EQ(5, solve(input));
}

TEST(solve, max_sequence_in_the_middle) {
  int values[] = {1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 0};
  auto input = generator(values);
  ASSERT_EQ(4, solve(input));
}

TEST(solve, max_sequence_at_the_end) {
  int values[] = {1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 4, 4, 4, 0};
  auto input = generator(values);
  ASSERT_EQ(6, solve(input));
}

}
}