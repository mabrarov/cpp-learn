#include <functional>
#include <gtest/gtest.h>
#include <task1_lib.hpp>

namespace cpp_learn {
namespace task1 {

TEST(solve, no_items) {
  std::function<int()> input_generator = []() { return 0; };
  ASSERT_EQ(0, solve(input_generator));
}

TEST(solve, singe_item) {
  int values[] = {1, 0};
  std::function<int()>
      input_generator = [n = 0, values]() mutable { return values[n++]; };
  ASSERT_EQ(1, solve(input_generator));
}

TEST(solve, equal_sequences_of_items) {
  int values[] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 0};
  std::function<int()>
      input_generator = [n = 0, values]() mutable { return values[n++]; };
  ASSERT_EQ(3, solve(input_generator));
}

TEST(solve, max_sequence_at_the_begining) {
  int values[] = {1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 0};
  std::function<int()>
      input_generator = [n = 0, values]() mutable { return values[n++]; };
  ASSERT_EQ(5, solve(input_generator));
}

TEST(solve, max_sequence_in_the_middle) {
  int values[] = {1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 0};
  std::function<int()>
      input_generator = [n = 0, values]() mutable { return values[n++]; };
  ASSERT_EQ(4, solve(input_generator));
}

TEST(solve, max_sequence_at_the_end) {
  int values[] = {1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 4, 4, 4, 0};
  std::function<int()>
      input_generator = [n = 0, values]() mutable { return values[n++]; };
  ASSERT_EQ(6, solve(input_generator));
}

}
}