ll fast_exp(ll base, ll exp, ll mod) {
  ll res = 1;
  while (exp) {
    if (exp & 1)  res = (res * base) % mod;
    base = (base * base) % mod;
    exp >>= 1;
  }
  return res % mod;
}
