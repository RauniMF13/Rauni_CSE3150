#include "lab9_algo.h"
#include <iostream>

using namespace std;

SquareMatrix remove_edges(SquareMatrix sm) {
  int n = sm.matrix.size();

  SquareMatrix result(n);
  
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if (sm.matrix[i][j] == 1 || sm.matrix[i][j] == -1){
	result.matrix[i][j] = 0;
      } else {
	result.matrix[i][j] = sm.matrix[i][j];
      }
    }
  }

  return result;
}

SquareMatrix normalize_and_divide_by_two(SquareMatrix sm) {
  int n = sm.matrix.size();

  SquareMatrix result(n);
  
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      result.matrix[j][i] = sm.matrix[i][j];
      result.matrix[j][i] /= 2;
    }
  }

  return result;
}

SquareMatrix get_zero_edges(SquareMatrix sm) {
  int n = sm.matrix.size();

  SquareMatrix result(n);

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(sm.matrix[i][j] == 0) {
	result.matrix[i][j] = 1;
      }
    }
  }
  return result;
}

SquareMatrix compute_reachability(SquareMatrix sm) {
  int n = sm.matrix.size();

  SquareMatrix result(n);

  for(int l = 2; l <= (log2(n) + 1); l++) {
    SquareMatrix M = sm * sm;
    M = remove_edges(M);
    M = normalize_and_divide_by_two(M);
    SquareMatrix Z = get_zero_edges(M);

    cout << l << ":" << endl;
    M.print();
    cout << "Z" << endl;
    Z.print();
    
    SquareMatrix MM  = (Z * M) * Z;

    cout << "MM" << endl;
    MM.print();
    
    sm = MM;
  }
  result = sm;
  
  return result;
}
