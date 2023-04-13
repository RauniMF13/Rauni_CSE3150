#include <vector>
#include "big_fractions.h"

#ifndef __FRACTION_VECTORS_H_
#define __FRACTION_VECTORS_H_

struct FractionMatrix {
  std::vector<std::vector<struct BigFraction>> matrix;

  void print() {
    for(auto i = matrix.begin(); i <= matrix.end(); i++) {
      
    }
  }

FractionMatrix(std::vector<std::vector<struct BigFraction>> matrix) : matrix(matrix) {};

  FractionMatrix operator*(struct FractionMatrix other) {
    std::vector<std::vector<struct BigFraction>> result;
    for (int i = 0; i < matrix.size(); i++) {
      std::vector<struct BigFraction> sub_result;
      for (int x = 0; x < matrix[i].size(); x++) {
	BigFraction new_fraction;
	for (int j = 0; j < other.matrix.size(); j++) {
	  new_fraction = new_fraction + (matrix[i][x] * other.matrix[j][x]);
	}
	sub_result.push_back(new_fraction);
      }
      result.push_back(sub_result);
    }
    return FractionMatrix(result);
  }
};

#endif
