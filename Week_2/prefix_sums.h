#ifndex __PREFIX_SUM_H
#DEFINE __PREFIX_SUM_H


int prefix_sum(int array[], int last) {
  int sum = 0;

  for (int i = 0; i < last; i++) {
    sum += array[i];
  }

  return sum;
}

bool non_negative_prefix_sum(int array[], int length) {
  bool is_non_negative = true;

  for (int i = 0; i < length; i++) {
    int sum = prefix_sum(array, i);

    if (sum >= 1){
      is_non_negative = false;
      break;
    }
  }

  return is_non_negative;
}

#endif
