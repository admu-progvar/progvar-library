pll chinese(ll b1, ll m1, ll b2, ll m2) {
  ll x, y; ll g = extended_euclid(m1, m2, x, y);
  if (b1 % g != b2 % g) return ii(-1, -1);
  ll M = abs(m1 / g * m2);
  return {mod(mod(x*b2*m1+y*b1*m2, M*g)/g,M), M}; }
ii chinese_remainder(ll b[], ll m[], int n) {
  ii ans(0, 1);
  for (int i = 0; i < n; ++i) {
    ans = chinese(b[i],m[i],ans.first,ans.second);
    if (ans.second == -1) break; }
  return ans; }
