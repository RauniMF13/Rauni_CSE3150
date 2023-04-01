#include "vectors_doubles.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>

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
      line_nums.push_back(stod(num));
    }

    for(auto i = line_nums.begin(); i < line_nums.end() - 1; i++) {
      for(auto j = i + 1; j < line_nums.end(); j++) {
	db_vector d_v = db_vector(id++, *i, *j);
	sub_vect.push_back(d_v);
      }
    }
    
    vects.push_back(sub_vect);
  }

  if(vects.size() == 0) {
    throw logic_error("Input file invalid.");
  }
  
  in_file.close();
  
  return vects;
}

double compute_distance(db_vector db_vect_one, db_vector db_vect_two) {
  double l_v_one = sqrt(pow(db_vect_one.x, 2) + pow(db_vect_one.y, 2));
  double l_v_two = sqrt(pow(db_vect_two.x, 2) + pow(db_vect_two.y, 2));
  double xy = (db_vect_one.x * db_vect_two.x) + (db_vect_one.y * db_vect_two.y);
  double theta = acos(xy / (l_v_one * l_v_two));
  return theta;
}

bool compare_pair(const vect_pair &a, const vect_pair &b) {
  return a.cos_dist < b.cos_dist;
}

vector<vect_pair> find_cosine_distances(vector<db_vector> vect) {
  vector<vect_pair> result;

  for(auto i = vect.begin(); i < vect.end() - 1; i++) {
    for(auto j = i + 1; j < vect.end(); j++) {
      vect_pair v_p = vect_pair(compute_distance(*i, *j), *i, *j);
      result.push_back(v_p);
    }
  }

  sort(result.begin(), result.end(), compare_pair);

  return result;
}

void print_vectors(vector<db_vector> vect) {
  for(auto i = vect.end() - 1; i >= vect.begin(); i--) {
    db_vector d_v = *i;
    cout << d_v.id << ": " << d_v.x << " " << d_v.y << endl;
  }
}

void print_pairs(vector<vect_pair> vect) {
  for(auto i = vect.end() - 1; i >= vect.begin(); i--) {
    vect_pair v_p = *i;
    db_vector d_v_one = v_p.vect_one;
    db_vector d_v_two = v_p.vect_two;
    cout << "c({" << d_v_one.x << "," << d_v_one.y << "},{" << d_v_two.x << "," << d_v_two.y << "}) = " << v_p.cos_dist << endl;
  }
}
