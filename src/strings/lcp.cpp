int lcp[N]; // lcp[i] = LCP(s[sa[i]:], s[sa[i+1]:])
void buildLCP(std::string s) {// build suffix array first
  for (int i = 0, k = 0; i < n; i++) {
    if (pos[i] != n - 1) {
      for(int j = sa[pos[i]+1]; s[i+k]==s[j+k];k++);
      lcp[pos[i]] = k; if (k > 0) k--;
  } else { lcp[pos[i]] = 0; } } }
