#ifndef __FISHER_YATES_H
#define __FISHER_YATES_H

int non_random_fcn();
int random_fcn();
void print_arr(int* arr, int length);
int* fisher_yates(int* arr, int length, int (* random_fcn)());
float* week2_algorithm(int* arr, int length, int (* random_fcn)(), int times_run);

#endif
