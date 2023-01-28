#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest/doctest/doctest.h"
#include "prefix_sums.h"

int nums_1[] = {2,-3,3,2};
int nums_2[] = {1,1,-1,-1};
int nums_3[] = {-1,-1,1,1};

TEST_CASE("Testing the prefix_sums functions."){
  CHECK(non_negative_prefix_sum(nums_1, 3) == false);
  CHECK(non_positive_prefix_sum(nums_1, 3) == false);
  CHECK(non_negative_prefix_sum(nums_2, 2) == false);
  CHECK(non_positive_prefix_sum(nums_3, 2) == false);
}
