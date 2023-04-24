#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../../doctest/doctest/doctest.h"
#include "lab9_algo.h"
#include <iostream>

using namespace std;

TEST_CASE("Lab 9 algorithm testing + square matrix functionality") {
  SquareMatrix sm_1;
  vector<vector<int>> v_1;
  vector<vector<int>> v_2;

  vector<int> sub_v_1_1;
  sub_v_1_1.push_back(1);
  sub_v_1_1.push_back(1);
  sub_v_1_1.push_back(-1);

  vector<int> sub_v_1_2;
  sub_v_1_2.push_back(-1);
  sub_v_1_2.push_back(1);
  sub_v_1_2.push_back(-1);

  vector<int> sub_v_1_3;
  sub_v_1_3.push_back(1);
  sub_v_1_3.push_back(-1);
  sub_v_1_3.push_back(1);
  
  v_1.push_back(sub_v_1_1);
  v_1.push_back(sub_v_1_2);
  v_1.push_back(sub_v_1_3);

  v_2.push_back(sub_v_1_1);
  v_2.push_back(sub_v_1_2);

  CHECK(v_1[0][1] == 1);
  CHECK(v_1[1][1] == 1);
  CHECK(v_1[2][1] == -1);
    
  SquareMatrix sm_2(v_1);
  
  CHECK_THROWS(SquareMatrix(v_2));

  SquareMatrix sm_3 = sm_2 * sm_2;
  
  sm_2.print();
  sm_3.print();

  SquareMatrix sm_3_removed_edges = remove_edges(sm_3);

  cout << "After removing +/- 1 edges:" << endl;
  sm_3_removed_edges.print();

  SquareMatrix sm_3_normalized = normalize_and_divide_by_two(sm_3_removed_edges);

  cout << "After normalizing:" << endl;
  sm_3_normalized.print();
  
  SquareMatrix zero_edges = get_zero_edges(sm_3_normalized);

  cout << "Zero edges matrix:" << endl;
  zero_edges.print();
  
  SquareMatrix res_matrix = compute_reachability(sm_3);

  cout << "Reachability matrix output:" << endl;
  res_matrix.print();
}
