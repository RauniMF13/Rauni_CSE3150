#include "SquareMatrix.h"
#include <algorithm>
#include <cmath>

#ifndef __LAB9_ALGO_H_
#define __LAB9_ALGO_H_

SquareMatrix remove_edges(SquareMatrix sm);
SquareMatrix normalize_and_divide_by_two(SquareMatrix sm);
SquareMatrix get_zero_edges(SquareMatrix sm);
SquareMatrix compute_reachability(SquareMatrix sm);

#endif
