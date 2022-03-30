#ifndef PVL_MATH_NUMTHEORY_PRIME_SIEVE_HPP_
#define PVL_MATH_NUMTHEORY_PRIME_SIEVE_HPP_ 1

#include <algorithm>
#include <vector>
#include <bitset>

namespace pvl {

struct prime_sieve {
  std::vector<bool> isc;
  std::vector<int> p;
  explicit prime_sieve(int n) : isc(n, 0) {
    for (int i = 2; i < n; i++) {
      if (!isc[i]) p.push_back(i);
      for (int j = 0; j < p.size() && i*p[j] < n; j++) {
        isc[i*p[j]] = 1;
        if (i%p[j] == 0) break;
      }
    }
  }
};

}  // namespace pvl

#endif  // PVL_MATH_NUMTHEORY_PRIME_SIEVE_HPP_
