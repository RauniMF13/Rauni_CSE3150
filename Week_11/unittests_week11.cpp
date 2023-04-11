#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "fraction_vectors.h"
#include "../../doctest/doctest/doctest.h"

#include <iostream>

using namespace std;


TEST_CASE("Testing big fraction struct creation and matrix operations.") {
  bigint num_big_int("10000000000000000000000000000000000000000000000000000000000000000000000000");
  bigint den_big_int("5000000000000000000000000000000000000000000000000000000000000000000000000");
  bigint div_big_int = num_big_int / den_big_int;

  CHECK(div_big_int == to_bigint(2));

  BigFraction my_fraction(num_big_int,den_big_int);
  bigint my_res = my_fraction.result();
  
  CHECK(my_fraction.fraction.first == num_big_int);
  CHECK(my_fraction.fraction.second == den_big_int);
  CHECK(my_res == div_big_int);

  bigint mult_res = my_fraction * my_fraction;

  CHECK(mult_res == to_bigint(4));
  
  vector<BigFraction> first_fraction_vector{ BigFraction(to_bigint(1924), to_bigint(36)),
					     BigFraction(to_bigint(9102), to_bigint(50)),
					     BigFraction(to_bigint(3859), to_bigint(32)),
					     BigFraction(to_bigint(5283), to_bigint(98)) };
  FractionMatrix first_fraction_matrix(first_fraction_vector);
}
