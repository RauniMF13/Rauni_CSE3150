#include "SquareMatrix.h"
#include <stdexcept>
#include <iostream>

using namespace std;

SquareMatrix::SquareMatrix() {
  
}

SquareMatrix::SquareMatrix(int n) {
  for(int i = 0; i < n; i++) {
    vector<int> sub_matrix;
    for(int j = 0; j < n; j++) {
      sub_matrix.push_back(0);
    }
    matrix.push_back(sub_matrix);
  }
}

SquareMatrix::SquareMatrix(vector<vector<int>> other) {
  for (auto i = other.begin(); i < other.end(); i++) {
    vector<int> i_V = *i;
    if (i_V.size() != other.size()) { throw logic_error("Invalid matrix input"); } 
  }
  matrix = other;
}

SquareMatrix::SquareMatrix(const SquareMatrix& other) : matrix(other.matrix) {}

SquareMatrix SquareMatrix::operator*(SquareMatrix other) const {
  int rows = matrix.size();
  int cols = rows; // square matrix

  vector<vector<int>> right_matrix = other.matrix;
  
  vector<vector<int>> result;

  for(int i = 0; i < rows; i++) {
    vector<int> sub_vect;
    for(int j = 0; j < cols; j++) {
      int t = 0;
      for (int k = 0; k < cols; k++) {
	t += matrix[i][k] * right_matrix[k][j];
      }
      sub_vect.push_back(t);
    }
    result.push_back(sub_vect);
  }

  SquareMatrix res_matrix(result);
  
  return res_matrix;
}

void SquareMatrix::print() {
  for(auto i = matrix.begin(); i < matrix.end(); i++) {
    vector<int> i_V = *i;
    cout << "[";
    for(auto j = i_V.begin(); j < i_V.end(); j++) {
      int v = *j;
      cout << v;
      if (j != i_V.end()) { cout << ", "; }
    }
    cout << "]" << endl;
  }
}
