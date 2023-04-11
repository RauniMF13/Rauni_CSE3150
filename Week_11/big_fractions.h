#include "../../bigint/Big Integer Library in Single file/bigint.h"

#include <utility>

#ifndef __BIG_FRACTIONS_H_
#define __BIG_FRACTIONS_H_

struct BigFraction {
  std::pair<bigint,bigint> fraction;
  
BigFraction(bigint num, bigint den) : fraction(std::make_pair(num, den)) {};
  
  bigint result() {
    return fraction.first / fraction.second;
  }

  bigint operator*(const BigFraction other) {
    return (fraction.first * other.fraction.first) / (fraction.second * other.fraction.second);
  }
};

#endif
