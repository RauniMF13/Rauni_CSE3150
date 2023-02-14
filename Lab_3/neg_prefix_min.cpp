#include <algorithm>
#include "../Week_2/prefix_sums.h"
#include "../Week_3/lab_week2.h"

using namespace std;

int neg_prefix_min(int array[], const int length) {
  int min_prefix{0}, sum{0};
  
  for (int i = 0; i < length; i++) {
    sum += array[i];
    min_prefix = min(min_prefix, sum);
  }
  
  return min_prefix;
}
 
int first_deepest_prefix_min(int array[], const int depth, const int length) {
  int min_prefix{0}, sum{0};
  
  int i;
  for(i = 0; i < length; i++) {
    sum += array[i];
    min_prefix = min(min_prefix, sum);
    if(depth == min_prefix) {
      break;
    }
  }

  return i;
}



int* shift_prefixes(int array[], const int length) {
  int neg_prefix_value = neg_prefix_min(array, length);
  int first_index_of_deepest = first_deepest_prefix_min(array, neg_prefix_value, length);
  
  int* new_array = new int[length -1];
  int new_index = 0;
  
  if(first_index_of_deepest != length -1) {
    for (int i = first_index_of_deepest + 1; i < length; i++) {
      new_array[new_index++] = array[i];
    }
    new_index--;
  }
  
  for(int i = 0; i < first_index_of_deepest; i++) {
    new_array[i + new_index] = array[i];
  }
  
  return new_array;
}
