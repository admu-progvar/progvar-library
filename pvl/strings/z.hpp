#ifndef PVL_STRINGS_Z_HPP_
#define PVL_STRINGS_Z_HPP_ 1

#include <vector>
#include <string>
#include <algorithm>

namespace pvl {

std::vector<int> compute_z(std::string s) {
  int n = s.length();
  std::vector<int> z(n, 0);
  int L = 0, R = 0;
  // Starting at i = 0 makes it O(n^2).
  for (int i = 1; i < n; i++) {
    if (i <= R) z[i] = std::min(R-i+1, z[i-L]);
    while(i+z[i] < n && s[z[i]] == s[i+z[i]]) z[i]++;
    if (i+z[i]-1 > R) {
      L = i;
      R = i+z[i]-1;
    }
  }
  z[0] = n;
  return z;
}

}  // namespace pvl

#endif  // PVL_STRINGS_Z_HPP_
