#include "adjacency_vectors.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

vector<vector<int>> get_adjacency_vectors(string file_name) {
  ifstream in_file;
  in_file.open(file_name);
  
  vector<vector<int>> vect;
  string line;
  
  while(getline(in_file, line)) {
    vector<int> sub_vect;
    string num;
    istringstream liness(line);

    while(getline(liness, num, ' ')) {
      sub_vect.push_back(stoi(num));
    }
    
    vect.push_back(sub_vect);
  }

  if(vect.size() == 0) {
    throw logic_error("Input file invalid.");
  }
  
  in_file.close();
  
  return vect;
}

void print_vectors(vector<vector<int>> vect) {
  cout << "Adjacency List:\n";
  for(int x = 0; x < vect.size(); x++) {
    cout << "Vertex " << x << " is adjacent to:";
    for(int y : vect[x]) {
      cout << " " << y;
    }
    cout << endl;
  }
}
