#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "perfect_numbers.h"
#include "../../doctest/doctest/doctest.h"

#include <iostream>

using namespace std;

TEST_CASE("Testing perfect number functionality") {

  srand(time(nullptr));
  
  // Test lambda functionality
  CHECK(6 == sum_divisors(6));

  CHECK(28 == sum_divisors(28));

  CHECK(1 != sum_divisors(1));

  CHECK(128 != sum_divisors(128));

  // Test functionality with vectors

  vector<int> test_vect;

  for(int i = 1; i <= 100; i++) test_vect.push_back(i);

  bool* test_results = test_perfect_integers(test_vect);

  // 6 is perfect
  CHECK(test_results[5]);

  // 28 is perfect
  CHECK(test_results[27]);

  // All other numbers aren't perfect

  for (int i = 1; i <= 100; i++) {
    if ((i != 5) && (i != 27)) CHECK(!test_results[i]);
  }
  
  delete test_results;
  
}
