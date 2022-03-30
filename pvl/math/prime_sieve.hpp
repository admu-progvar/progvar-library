#ifndef PVL_MATH_PRIME_SIEVE_HPP_
#define PVL_MATH_PRIME_SIEVE_HPP_ 1

#include <algorithm>
#include <vector>
#include <bitset>

namespace pvl {

struct prime_sieve {
    std::vector<bool> is_composite;
    std::vector<int> primes;
    explicit prime_sieve(int n) : is_composite(n, 0) {
        for (int i = 2; i < n; i++) {
            if (!is_composite[i]) primes.push_back(i);
            for (int j = 0;
                j < primes.size() && i*primes[j] < n;
                j++) {
                is_composite[i*primes[j]] = 1;
                if (i%primes[j] == 0) break;
            }
        }
    }
};

}  // namespace pvl

#endif  // PVL_MATH_PRIME_SIEVE_HPP_
