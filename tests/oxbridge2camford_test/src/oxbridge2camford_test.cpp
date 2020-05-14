#include <stdexcept>
#include <gtest/gtest.h>
#include <oxbridge2camford_lib.hpp>

namespace cpp_learn {
namespace oxbridge2camford {

TEST(find_min_camford_sum, zero_items) {
  ASSERT_THROW(find_min_camford_sum(1, 0), std::exception);
}

TEST(find_min_camford_sum, too_small_average) {
  ASSERT_THROW(find_min_camford_sum(1, 1), std::exception);
}

TEST(find_min_camford_sum, too_large_average) {
  ASSERT_THROW(find_min_camford_sum(200, 1), std::exception);
}

TEST(find_min_camford_sum, single_min_item_camford_40) {
  ASSERT_EQ(40, find_min_camford_sum(85, 1));
}

TEST(find_min_camford_sum, single_max_item_camford_40) {
  ASSERT_EQ(40, find_min_camford_sum(100, 1));
}

TEST(find_min_camford_sum, single_min_item_camford_35) {
  ASSERT_EQ(35, find_min_camford_sum(80, 1));
}

TEST(find_min_camford_sum, single_max_item_camford_35) {
  ASSERT_EQ(35, find_min_camford_sum(84, 1));
}

TEST(find_min_camford_sum, single_min_item_camford_30) {
  ASSERT_EQ(30, find_min_camford_sum(75, 1));
}

TEST(find_min_camford_sum, single_max_item_camford_30) {
  ASSERT_EQ(30, find_min_camford_sum(79, 1));
}

TEST(find_min_camford_sum, single_min_item_camford_25) {
  ASSERT_EQ(25, find_min_camford_sum(70, 1));
}

TEST(find_min_camford_sum, single_max_item_camford_25) {
  ASSERT_EQ(25, find_min_camford_sum(74, 1));
}

TEST(find_min_camford_sum, single_min_item_camford_20) {
  ASSERT_EQ(20, find_min_camford_sum(60, 1));
}

TEST(find_min_camford_sum, single_max_item_camford_20) {
  ASSERT_EQ(20, find_min_camford_sum(69, 1));
}

TEST(find_max_camford_sum, zero_items) {
  ASSERT_THROW(find_max_camford_sum(1, 0), std::exception);
}

TEST(find_max_camford_sum, too_small_average) {
  ASSERT_THROW(find_max_camford_sum(1, 1), std::exception);
}

TEST(find_max_camford_sum, too_large_average) {
  ASSERT_THROW(find_max_camford_sum(200, 1), std::exception);
}

TEST(find_max_camford_sum, single_min_item_camford_40) {
  ASSERT_EQ(40, find_max_camford_sum(85, 1));
}

TEST(find_max_camford_sum, single_max_item_camford_40) {
  ASSERT_EQ(40, find_max_camford_sum(100, 1));
}

TEST(find_max_camford_sum, single_min_item_camford_35) {
  ASSERT_EQ(35, find_max_camford_sum(80, 1));
}

TEST(find_max_camford_sum, single_max_item_camford_35) {
  ASSERT_EQ(35, find_max_camford_sum(84, 1));
}

TEST(find_max_camford_sum, single_min_item_camford_30) {
  ASSERT_EQ(30, find_max_camford_sum(75, 1));
}

TEST(find_max_camford_sum, single_max_item_camford_30) {
  ASSERT_EQ(30, find_max_camford_sum(79, 1));
}

TEST(find_max_camford_sum, single_min_item_camford_25) {
  ASSERT_EQ(25, find_max_camford_sum(70, 1));
}

TEST(find_max_camford_sum, single_max_item_camford_25) {
  ASSERT_EQ(25, find_max_camford_sum(74, 1));
}

TEST(find_max_camford_sum, single_min_item_camford_20) {
  ASSERT_EQ(20, find_max_camford_sum(60, 1));
}

TEST(find_max_camford_sum, single_max_item_camford_20) {
  ASSERT_EQ(20, find_max_camford_sum(69, 1));
}

TEST(find_min_camford_sum, single_item) {
  ASSERT_EQ(30, find_max_camford_sum(77, 1));
}

TEST(find_max_camford_sum, single_item) {
  ASSERT_EQ(30, find_max_camford_sum(77, 1));
}

TEST(find_min_camford_sum, two_items) {
  ASSERT_EQ(60, find_min_camford_sum(77, 2));
}

TEST(find_max_camford_sum, two_items) {
  ASSERT_EQ(60, find_max_camford_sum(77, 2));
}

TEST(find_min_camford_sum, three_items) {
  ASSERT_EQ(80, find_min_camford_sum(77, 3));
}

TEST(find_max_camford_sum, three_items) {
  ASSERT_EQ(100, find_max_camford_sum(77, 3));
}

TEST(find_min_camford_sum, nine_items) {
  ASSERT_EQ(230, find_min_camford_sum(77, 9));
}

TEST(find_max_camford_sum, nine_items) {
  ASSERT_EQ(300, find_max_camford_sum(77, 9));
}

}
}
