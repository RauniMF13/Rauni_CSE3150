#include <cstdlib>

#ifndef __FISHER_YATES_H
#define __FISHER_YATES_H

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

int non_random_fcn();
int random_fcn();
void print_arr(int* arr, int length);
float* week2_algorithm(int* arr, int length, int (* random_fcn)(), int times_run);

#endif
