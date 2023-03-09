#include <vector>
#include <cstdlib>
#include <algorithm>

#ifndef __PERFECT_NUMBERS_H_
#define __PERFECT_NUMBERS_H_

using namespace std;

auto sum_divisors = [](int input) {
  int sum = 0;

  if(input == 1) return 0;

  for(int i = 1; i <= input / 2; i++) {
    if(input % i == 0) sum += i;
  }

  return sum;
};

bool* test_perfect_integers(vector<int>& vect) {
  bool* result = (bool*)malloc(sizeof(bool)*vect.size());
  int i = 0;
  
  for_each(vect.begin(), vect.end(), [&](int num) {
      result[i++] = (num == sum_divisors(num));
    });

  return result;
}

#endif
