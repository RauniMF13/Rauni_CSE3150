#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "fraction_vectors.h"
#include "../../doctest/doctest/doctest.h"

using namespace std;


TEST_CASE("Testing big fraction struct creation and matrix operations.") {
  bigint num_big_int("10000000000000000000000000000000000000000000000000000000000000000000000000");
  bigint den_big_int("5000000000000000000000000000000000000000000000000000000000000000000000000");
  bigint div_big_int = num_big_int / den_big_int;

  CHECK(div_big_int == to_bigint(2));

  BigFraction my_fraction(num_big_int,den_big_int);

  my_fraction.print();
  
  CHECK(my_fraction.fraction.first == num_big_int);
  CHECK(my_fraction.fraction.second == den_big_int);

  BigFraction mult_res = my_fraction * my_fraction;

  CHECK(mult_res.fraction.first == (num_big_int * num_big_int));
  CHECK(mult_res.fraction.second == (den_big_int * den_big_int));
  
  BigFraction addi_res = my_fraction + my_fraction;

  addi_res.print();
  
  CHECK(addi_res.fraction.first == (num_big_int + num_big_int));
  CHECK(addi_res.fraction.second == den_big_int);

  BigFraction a(to_bigint(1),to_bigint(4));
  BigFraction b(to_bigint(2),to_bigint(3));
  BigFraction c(to_bigint(2),to_bigint(5));
  BigFraction d(to_bigint(3),to_bigint(4));
  
  vector<vector<BigFraction>> first_fraction_vector = { {a,b},
							{c,d} };
  FractionMatrix first_fraction_matrix(first_fraction_vector);
}
