#include "vectors_doubles.h"

#include <iostream>

using namespace std;

int main() {
  vector<vector<db_vector>> vects = get_db_vectors("vectors.txt");

  print_vectors(vects[0]);

  return 0;
}
