#ifndef __SQUARE_MATRIX_H_
#define __SQUARE_MATRIX_H_

#include <vector>

struct SquareMatrix {

  std::vector<std::vector<int>> matrix;
  
  SquareMatrix();
  SquareMatrix(int n);
  SquareMatrix(std::vector<std::vector<int>> matrix);
  SquareMatrix(const struct SquareMatrix& sm);
  SquareMatrix operator*(struct SquareMatrix other) const;
  void print();
};

#endif
