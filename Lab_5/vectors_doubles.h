#include <vector>
#include <string>

#ifndef __VECTORS_2D_H_
#define __VECTORS_2D_H_

struct db_vector {
  int id;
  double x;
  double y;
  db_vector(const db_vector & d_V) : id(d_V.id), x(d_V.x), y(d_V.y) {};
  db_vector(const int id, const double x, const double y) : id(id), x(x), y(y) {};
  db_vector() : id(-1), x(0), y(0) {};
};

std::vector<struct db_vector> get_db_vectors(std::string file_name);
void print_vectors(std::vector<struct db_vector> vect);

#endif
