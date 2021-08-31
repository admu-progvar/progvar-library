pll null(-1, -1); // needs extended euclidean
pll diophantine(ll a, ll b, ll c) {
  if (!a && !b) return c ? null : {0, 0};
  if (!a) return c % b ? null : {0, c / b};
  if (!b) return c % a ? null : {c / a, 0};
  ll x, y; ll g = extended_euclid(a, b, x, y);
  if (c % g) return null;
  y = mod(y * (c/g), a/g);
  if (y == 0) y += abs(a/g); // prefer positive sol.
  return {(c - b*y)/a, y}; }
