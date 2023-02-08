#include "lab_week2.h"
#include "../Week_2/prefix_sums.h"
#include <iostream>
#include <cstdlib>

using namespace std;

int non_random_fcn() {
  return 0;
}

int random_fcn() {
  return rand();
}

void print_arr(int* arr, int length) {
  for(int i = 0; i < length; i++) {
      cout << arr[i] << " ";
  }

  cout << endl;
}

int* fisher_yates(int arr[], int length, int (* random_fcn)()) {
  int* result = (int*)malloc(sizeof(int) * length);

  for(int i = 0; i < length; i++) {
    result[i] = arr[i];
  }

  for(int i = 0; i < (length - 2); i++) {
    int j = random_fcn() % (length - i) + i;

    int temp = result[i];

    result[i] = result[j];
    result[j] = temp;
  }

  return result;
}

float* week2_algorithm(int* arr, int length, int (* random_fcn)(), int times_run) {
  int num_passed = 0;
  srand(time(nullptr));
  
  for(int i = 0; i < times_run; i++) {
    int* shuffled_arr = fisher_yates(arr, length, random_fcn);
    
    bool is_non_positive = non_positive_prefix_sum(shuffled_arr, length);
    bool is_non_negative = non_negative_prefix_sum(shuffled_arr, length);
    
    if(is_non_positive || is_non_negative) {
      num_passed++;
    }
    
    delete shuffled_arr;
  }

  float percent_passed = (float)num_passed / times_run;

  float* result = (float*)malloc(sizeof(float) * 2);
  result[0] = (float)num_passed;
  result[1] = percent_passed;
  
  return result;
}
