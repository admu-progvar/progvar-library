pll modsolver(ll a, ll b, ll m) {
  ll x, y; ll g = extended_euclid(a, m, x, y);
  if (b % g != 0) return {-1, -1};
  return {mod(x*b/g, m/g), abs(m/g)}; }
