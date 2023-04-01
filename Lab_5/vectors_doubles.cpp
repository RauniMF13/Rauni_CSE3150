#include "vectors_doubles.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

vector<vector<db_vector>> get_db_vectors(string file_name) {
  ifstream in_file;
  in_file.open(file_name);
  
  vector<vector<db_vector>> vects;
  string line;

  int id{0};
  
  while(getline(in_file, line)) {
    vector<db_vector> sub_vect;
    vector<double> line_nums;
    
    string num;
    istringstream liness(line);
    
    while(getline(liness, num, ' ')) {
      cout << stod(num) << endl;
      line_nums.push_back(stod(num));
    }

    cout << line_nums.size() << endl;

    /*
    for(int i = 0; i < line_nums.size() - 2; i++) {
      for(int j = i + 1; i < line_nums.size() - 1; j++) {
	db_vector d_v = db_vector(id++, line_nums[i], line_nums[j]);
	cout << d_v.x << ", " << d_v.y << endl;
	sub_vect.push_back(d_v);
      }
    }
    */
    
    vects.push_back(sub_vect);
  }

  if(vects.size() == 0) {
    throw logic_error("Input file invalid.");
  }
  
  in_file.close();
  
  return vects;
}

void print_vectors(vector<db_vector> vect) {
  for(auto i = vect.end() - 1; i >= vect.begin(); i--) {
    db_vector d_v = *i;
    cout << d_v.id << ": " << d_v.x << " " << d_v.y << endl;
  }
}
