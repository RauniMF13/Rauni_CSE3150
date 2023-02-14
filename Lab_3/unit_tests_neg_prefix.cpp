#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../../doctest/doctest/doctest.h"
#include "neg_prefix_min.h"

int nums_0[] = {};
int nums_1[] = {-1,-1,1,1};
int nums_2[] = {1,1,-1,-1};
int nums_3[] = {-1,-1,-1,-1};
int nums_4[] = {-1,-1,1,1,-1,-1,-1,1,1};
int nums_5[] = {-1,-1,1,1,-1,-1,-1,1,1,-1,-1,-1,1};
int nums_6[] = {1,-1,-1,1,1,-1,1,-1,-1};


TEST_CASE("Testing neg_prefix_min function") {
  CHECK(neg_prefix_min(nums_0, sizeof(nums_0)/sizeof(nums_0[0])) == 0);
  CHECK(neg_prefix_min(nums_1, sizeof(nums_1)/sizeof(nums_1[0]) + 2) == -2);
  CHECK(neg_prefix_min(nums_1, sizeof(nums_1)/sizeof(nums_1[0])) == -2);
  CHECK(neg_prefix_min(nums_2, sizeof(nums_2)/sizeof(nums_2[0])) == 0);
  CHECK(neg_prefix_min(nums_3, sizeof(nums_3)/sizeof(nums_3[0])) == -4);
  CHECK(neg_prefix_min(nums_4, sizeof(nums_4)/sizeof(nums_4[0])) == -3);
  CHECK(neg_prefix_min(nums_5, sizeof(nums_5)/sizeof(nums_5[0])) == -4);
  CHECK(neg_prefix_min(nums_6, sizeof(nums_6)/sizeof(nums_6[0])) == -1);
  
  int d_0 = neg_prefix_min(nums_0, sizeof(nums_0)/sizeof(nums_0[0]));
  CHECK(first_deepest_prefix_min(nums_0, d_0, sizeof(nums_0)/sizeof(nums_0[0])) == 0);
  
  int d_1 = neg_prefix_min(nums_1, sizeof(nums_1)/sizeof(nums_1[0]));
  CHECK(first_deepest_prefix_min(nums_1, d_1, sizeof(nums_1)/sizeof(nums_1[0])) == 1);
  
  /* if a list is a min depth of 0, then the first depth 0 starts at position 0
  */
    
  
  int d_2 = neg_prefix_min(nums_2, sizeof(nums_2)/sizeof(nums_2[0]));
  CHECK(first_deepest_prefix_min(nums_2, d_2, sizeof(nums_2)/sizeof(nums_2[0])) == 0);
  
  int d_3 = neg_prefix_min(nums_3, sizeof(nums_3)/sizeof(nums_3[0]));
  CHECK(first_deepest_prefix_min(nums_3, d_3, sizeof(nums_3)/sizeof(nums_3[0])) == 3);
  
  
  int d_6 = neg_prefix_min(nums_6, sizeof(nums_6)/sizeof(nums_6[0]));
  CHECK(first_deepest_prefix_min(nums_6, d_6, sizeof(nums_6)/sizeof(nums_6[0])) == 2);

  int ballot_minus_1_list3[] {1,-1,-1};

  int* actual = shift_prefixes(ballot_minus_1_list3, sizeof(ballot_minus_1_list3)/sizeof(ballot_minus_1_list3[0]));
  
  CHECK(actual[0] == 1);
  CHECK(actual[1] == -1);
  
}
