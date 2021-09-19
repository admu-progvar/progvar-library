ll mod(ll x, ll m) { // use this instead of x % m
  if (m == 0) return 0;
  if (m < 0) m *= -1;
  return (x%m + m) % m; // always nonnegative
}
ll extended_euclid(ll a, ll b, ll &x, ll &y) {
  if (b==0) {x = 1; y = 0; return a;}
  ll g = extended_euclid(b, a%b, x, y);
  ll z = x - a/b*y;
  x = y; y = z; return g;
}
