int MAXN = 1e5+1, MOD = 1e9+7;
struct hasher {
  int n;
  std::vector<ll> *p_pow, *h_ans;
  hash(vi &s, vi primes) : n(primes.size()) {
    p_pow = new std::vector<ll>[n];
    h_ans = new std::vector<ll>[n];
    for (int i = 0; i < n; ++i) {
      p_pow[i] = std::vector<ll>(MAXN);
      p_pow[i][0] = 1;
      for (int j = 0; j+1 < MAXN; ++j)
        p_pow[i][j+1] = (p_pow[i][j] * primes[i]) % MOD;
      h_ans[i] = std::vector<ll>(MAXN);
      h_ans[i][0] = 0;
      for (int j = 0; j < s.size(); ++j)
        h_ans[i][j+1] = (h_ans[i][j] +
                         s[j] * p_pow[i][j]) % MOD; } } };
