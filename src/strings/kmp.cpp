int par[N]; // parent table
void buildKMP(string& f) {
  par[0] = -1, par[1] = 0;
  int i = 2, j = 0;
  while (i <= f.length()) {
    if (f[i-1] == f[j]) par[i++] = ++j;
    else if (j > 0) j = par[j];
    else par[i++] = 0; } }
std::vector<int> KMP(string& s, string& f) {
  buildKMP(f); // call once if f is the same
  int i = 0, j = 0; vector<int> ans;
  while (i + j < s.length()) {
    if (s[i + j] == f[j]) {
      if (++j == f.length()) {
        ans.push_back(i);
        i += j - par[j];
        if (j > 0) j = par[j]; }
    } else {
      i += j - par[j];
      if (j > 0) j = par[j]; }
  } return ans; }
