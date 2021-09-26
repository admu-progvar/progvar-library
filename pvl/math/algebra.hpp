#ifndef PVL_MATH_ALGEBRA_HPP_
#define PVL_MATH_ALGEBRA_HPP_ 1

#include <algorithm>

#include "math/constants.hpp"


namespace pvl {

namespace alg {

template <typename T>
T add(T a, T b) { return a + b; }

template <typename T>
T add_id() { return T(0); }

template <typename T>
T mult(T a, T b) { return a * b; }

template <typename T>
T mult_id() { return T(1); }

template <typename T>
T min(T a, T b) { return std::min(a, b); }

template <typename T>
T min_id() { return T(INT_INF); }

template <typename T>
T strict_eq(T a, T b) { return a == b; }

template <typename T>
T approx_eq(T a, T b) { return std::abs(a - b) < EPS; }

}  // namespace alg

}  // namespace pvl

#endif  // PVL_MATH_ALGEBRA_HPP_
