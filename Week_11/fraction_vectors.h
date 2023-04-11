#include <vector>
#include "big_fractions.h"

#ifndef __FRACTION_VECTORS_H_
#define __FRACTION_VECTORS_H_

struct FractionMatrix {
  std::vector<struct BigFraction> matrix;

FractionMatrix(std::vector<struct BigFraction>) : matrix(matrix) {};

  std::vector<bigint> operator*(struct FractionMatrix other) {
    std::vector<bigint> result;
    for (auto x = matrix.begin(); x <= matrix.end(); x++) {
      bigint new_bigint;
      for (auto y = other.matrix.begin(); y <= other.matrix.end(); y++) {
	new_bigint += *x * *y;
      }
      result.push_back(new_bigint);
    }
    return result;
  }
};

#endif
