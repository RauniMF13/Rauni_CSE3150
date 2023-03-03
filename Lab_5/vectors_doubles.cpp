#include "vectors_doubles.h"

#include <iostream>
#include <fstream>

using namespace std;

vector<db_vector> get_db_vectors(string file_name) {
  ifstream in_file;
  in_file.open(file_name);
  
  vector<db_vector> vect;

  int id{0};
  double x{0}, y{0};
  
  while(in_file) {
    db_vector d_v;
    if(!(in_file >> x >> y)) {
      if(in_file.eof()) {
	break;
      } else {
	throw logic_error("Input file invalid.");
      }
    }
    d_v = db_vector(id++, x, y);
    vect.push_back(d_v);
  }

  if(vect.size() == 0) {
    throw logic_error("Input file invalid.");
  }
  
  in_file.close();
  
  return vect;
}

void print_vectors(vector<db_vector> vect) {
  for(auto i = vect.end() - 1; i >= vect.begin(); i--) {
    db_vector d_v = *i;
    cout << d_v.id << ": " << d_v.x << " " << d_v.y << endl;
  }
}
