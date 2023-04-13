#include "../../bigint/Big Integer Library in Single file/bigint.h"

#include <utility>
#include <iostream>

#ifndef __BIG_FRACTIONS_H_
#define __BIG_FRACTIONS_H_

struct BigFraction {
  std::pair<bigint,bigint> fraction;

  BigFraction() : fraction(std::make_pair(to_bigint(1), to_bigint(1))) {};
BigFraction(bigint num, bigint den) : fraction(std::make_pair(num, den)) {};
  
  void print() {
    std::cout << fraction.first << " / " << fraction.second << std::endl;
  }

  BigFraction operator+(BigFraction other) {
    bigint gcd = big_gcd(fraction.second, other.fraction.second);

    bigint den = (fraction.second * other.fraction.second) / gcd;
    bigint num = (fraction.first * (den / fraction.second)) + (other.fraction.first * (den / other.fraction.second));
    
    BigFraction result(num, den);
    return result;
  }
  
  BigFraction operator*(BigFraction other) {
    BigFraction result((fraction.first * other.fraction.first),(fraction.second * other.fraction.second));
    return result;
  }
};

#endif
