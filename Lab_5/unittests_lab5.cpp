#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "vectors_doubles.h"
#include "../../doctest/doctest/doctest.h"

#include <iostream>

using namespace std;

TEST_CASE("Testing vector cosine distance functionality"){
  vector<vector<db_vector>> vects = get_db_vectors("vectors.txt");

  print_vectors(vects[0]);
  print_vectors(vects[1]);

  vector<vect_pair> cos_distances = find_cosine_distances(vects[0]);

  print_pairs(cos_distances);

  vector<vector<db_vector>> vects_example = get_db_vectors("vectors_example.txt");

  vector<vect_pair> cos_dist_example = find_cosine_distances(vects_example[0]);

  print_pairs(cos_dist_example);

  // Calculate cosine distance between two vectors given in example
  CHECK(cos_dist_example[13].cos_dist == doctest::Approx(0.625485));
}
