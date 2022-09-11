int z[N]; // z[i] = lcp(s, s[i:])
void compute_z(string s) {
  int n = s.length(), L = 0, R = 0; z[0] = 0;
  for (int i = 1; i < n; i++) {
    if (i <= R) z[i] = min(R-i+1, z[i-L]);
    while(i+z[i] < n && s[z[i]] == s[i+z[i]]) z[i]++;
    if (i+z[i]-1 > R) L = i, R = i+z[i]-1; } }
