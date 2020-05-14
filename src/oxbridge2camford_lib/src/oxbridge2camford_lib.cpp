#include <algorithm>
#include <stdexcept>
#include <string>
#include <oxbridge2camford_lib.hpp>

namespace {

const int min_oxbridge = 60;
const int max_oxbridge = 100;

const int min_oxbridge_for_max_camford = 85;
const int max_oxbridge_for_min_camford = 69;

const int min_camford = 20;
const int max_camford = 40;

// Conversion of oxbridge to camford * 10
// 85-100 -> 40
// 80-84  -> 35
// 75-79  -> 30
// 70-74  -> 25
// 60-69  -> 20

const int oxbridge_to_camford_dict[41] = {
    20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
    25, 25, 25, 25, 25, 30, 30, 30, 30, 30,
    35, 35, 35, 35, 35, 40, 40, 40, 40, 40,
    40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
    40
};

const int oxbridge_dec_dict[41] = {
    59, 59, 59, 59, 59, 59, 59, 59, 59, 59,
    69, 69, 69, 69, 69, 74, 74, 74, 74, 74,
    79, 79, 79, 79, 79, 84, 84, 84, 84, 84,
    84, 84, 84, 84, 84, 84, 84, 84, 84, 84,
    84
};

const int oxbridge_inc_dict[41] = {
    70,  70,  70,  70,  70,  70,  70,  70,  70,  70,
    75,  75,  75,  75,  75,  80,  80,  80,  80,  80,
    85,  85,  85,  85,  85,  101, 101, 101, 101, 101,
    101, 101, 101, 101, 101, 101, 101, 101, 101, 101,
    101
};

int find_min(int oxbridge_sum, int n) {
  if (1 == n) {
    return oxbridge_to_camford_dict[oxbridge_sum - min_oxbridge];
  }

  const int max_possible_oxbridge =
      (std::min)(max_oxbridge, oxbridge_sum - min_oxbridge * (n - 1));
  const int min_possible_oxbridge =
      (std::max)(min_oxbridge, oxbridge_sum - max_oxbridge * (n - 1));
  const int min_possible_camford =
      oxbridge_to_camford_dict[min_possible_oxbridge - min_oxbridge];

  int min_camford_sum = max_camford * n;
  int oxbridge = max_possible_oxbridge;

  while (true) {
    int camford = oxbridge_to_camford_dict[oxbridge - min_oxbridge];
    int other_camford_sum = find_min(oxbridge_sum - oxbridge, n - 1);
    int camford_sum = other_camford_sum + camford;
    if (camford_sum < min_camford_sum) {
      min_camford_sum = camford_sum;
    } else if (camford_sum - min_camford_sum >= camford - min_possible_camford) {
      break;
    }
    if (oxbridge <= max_oxbridge_for_min_camford) {
      break;
    }
    oxbridge = oxbridge_dec_dict[oxbridge - min_oxbridge];
  }

  return min_camford_sum;
}

int find_max(int oxbridge_sum, int n) {
  if (1 == n) {
    return oxbridge_to_camford_dict[oxbridge_sum - min_oxbridge];
  }

  const int min_possible_oxbridge =
      (std::max)(min_oxbridge, oxbridge_sum - max_oxbridge * (n - 1));
  const int max_possible_oxbridge =
      (std::min)(max_oxbridge, oxbridge_sum - min_oxbridge * (n - 1));
  const int max_possible_camford =
      oxbridge_to_camford_dict[max_possible_oxbridge - min_oxbridge];

  int max_camford_sum = min_camford * n;
  int oxbridge = min_possible_oxbridge;

  while (true) {
    int camford = oxbridge_to_camford_dict[oxbridge - min_oxbridge];
    int other_camford_sum = find_max(oxbridge_sum - oxbridge, n - 1);
    int camford_sum = other_camford_sum + camford;
    if (camford_sum > max_camford_sum) {
      max_camford_sum = camford_sum;
    } else if (max_camford_sum - camford_sum >= max_possible_camford - camford) {
      break;
    }
    if (oxbridge >= min_oxbridge_for_max_camford) {
      break;
    }
    oxbridge = oxbridge_inc_dict[oxbridge - min_oxbridge];
  }

  return max_camford_sum;
}

} // anonymous namespace

int cpp_learn::oxbridge2camford::find_min_camford_sum(
    int oxbridge_average, int n) {
  if (n < 1) {
    throw std::invalid_argument("Number of items should be > 0");
  }
  if (oxbridge_average < min_oxbridge) {
    throw std::invalid_argument(
        "Average should be >= " + std::to_string(min_oxbridge));
  }
  if (oxbridge_average > max_oxbridge) {
    throw std::invalid_argument(
        "Average should be <= " + std::to_string(max_oxbridge));
  }
  return find_min(oxbridge_average * n, n);
}

int cpp_learn::oxbridge2camford::find_max_camford_sum(
    int oxbridge_average, int n) {
  if (n < 1) {
    throw std::invalid_argument("Number of items should be > 0");
  }
  if (oxbridge_average < min_oxbridge) {
    throw std::invalid_argument(
        "Average should be >= " + std::to_string(min_oxbridge));
  }
  if (oxbridge_average > max_oxbridge) {
    throw std::invalid_argument(
        "Average should be <= " + std::to_string(max_oxbridge));
  }
  return find_max(oxbridge_average * n, n);
}
