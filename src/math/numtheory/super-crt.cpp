pll super_chinese(ll a[], ll b[], ll m[], int n) {
  pll ans(0, 1);
  for (int i = 0; i < n; ++i) {
    pll two = modsolver(a[i], b[i], m[i]);
    if (two.second == -1) return two;
    ans = chinese(ans.first, ans.second,
    two.first, two.second);
    if (ans.second == -1) break; }
  return ans; }
