ll totient(ll n) {
  if (n <= 1) return 1;
  ll tot = n;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) tot -= tot / i;
    while (n % i == 0) n /= i; }
  if (n > 1) tot -= tot / n;
  return tot; }
