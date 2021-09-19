int z[N]; // z[i] = lcp(s, s[i:])
void computeZ(string s) {
  int n = s.length(), L = 0, R = 0; z[0] = n;
  for (int i = 1; i < n; i++) {
    if (i > R) {
      L = R = i;
      while (R < n && s[R - L] == s[R]) R++;
      z[i] = R - L; R--;
    } else {
      int k = i - L;
      if (z[k] < R - i + 1) z[i] = z[k];
      else {
        L = i;
        while (R < n && s[R - L] == s[R]) R++;
        z[i] = R - L; R--; } } } }
