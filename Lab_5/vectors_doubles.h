#include <vector>
#include <string>

#ifndef __VECTORS_DOUBLES_H_
#define __VECTORS_DOUBLES_H_

struct db_vector {
  int id;
  double x;
  double y;
  db_vector(const db_vector & d_V) : id(d_V.id), x(d_V.x), y(d_V.y) {};
  db_vector(const int id, const double x, const double y) : id(id), x(x), y(y) {};
  db_vector() : id(-1), x(0), y(0) {};
};

struct vect_pair {
  double cos_dist;
  struct db_vector vect_one;
  struct db_vector vect_two;
  vect_pair(const double cos_dist, const struct db_vector vect_one, const struct db_vector vect_two) : cos_dist(cos_dist), vect_one(vect_one), vect_two(vect_two) {};
};

std::vector<std::vector<struct db_vector>> get_db_vectors(std::string file_name);
double compute_distance(struct db_vector db_vect_one, struct db_vector db_vect_two);
std::vector<struct vect_pair> find_cosine_distances(std::vector<struct db_vector> vect);
void print_vectors(std::vector<struct db_vector> vect);
void print_pairs(std::vector<struct vect_pair> vect);

#endif
