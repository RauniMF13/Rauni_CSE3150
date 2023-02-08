#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../../doctest/doctest/doctest.h"
#include "lab_week2.h"

using namespace std;

TEST_CASE("Testing the fisher-yates functions.") {
  int arr[] = {1,1,1,1,1,1,-1,-1,-1,-1,-1,-1};
  int length = (sizeof(arr) / sizeof(int));
  int times_run;

  cout << "Enter the number of times to run the algorithm: ";
  cin >> times_run;

  float* results = week2_algorithm(arr, length, &random_fcn, times_run);

  cout << "Number passed: " << results[0] << endl;
  cout << "Percent passed: " << results[1] << endl;

  CHECK(results[0] > 0);

  delete results;
}
