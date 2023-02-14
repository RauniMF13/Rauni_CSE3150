//#include "../Week_2/prefix_sums.h"
//#include "../Week_3/lab_week2.h"

#ifndef __NEG_PREFIX_MIN_H_
#define __NEG_PREFIX_MIN_H_

int neg_prefix_min(int array[], const int length);
int first_deepest_prefix_min(int array[], const int depth, const int length);
int* shift_prefixes(int array[], const int length);
int* balance_arr(int* array, int length, int (* random_fcn)());
float lab3_algorithm(int* arr, int length, int (* random_fcn)(), int times_run);


#endif
