#include "adjacency_vectors.h"

using namespace std;

int main(){
  vector<vector<int>> my_vect = get_adjacency_vectors("ints_file.txt");

  print_vectors(my_vect);
  
  return 0;
}
