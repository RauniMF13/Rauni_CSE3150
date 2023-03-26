#include <vector>
#include <string>

#ifndef __VECTORS_2D_H_
#define __VECTORS_2D_H_

struct int_vector {
  int id;
  int x;
  int y;
  int_vector(const int_vector & i_V) : id(i_V.id), x(i_V.x), y(i_V.y) {};
  int_vector(const int id, const int x, const int y) : id(id), x(x), y(y) {};
  int_vector() : id(-1), x(0), y(0) {};
};

std::vector<struct int_vector> get_2D_vectors(std::string file_name);
void print_vectors(std::vector<struct int_vector> vect);

#endif
