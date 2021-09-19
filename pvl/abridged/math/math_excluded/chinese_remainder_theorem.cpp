typedef std::pair<ll, ll> pll;
ll crt(std::vector<pll> &data) {
  ll M = 1, res = 0;
  for (int i = 0; i < data.size(); ++i)
    M *= data[i].second;
  for (int i = 0; i < data.size(); ++i) {
    ll Mi = M/data[i].second;
    res = (res + data[i].first * Mi *
                 mod_inverse(Mi, data[i].second)) % M;
  }
  return res;
}
pll crt_generalized(std::vector<pll> &data) {
  std::map<ll, pll> decomp;
  for (int i = 0; i < data.size(); ++i) {
    ll m = data[i].second;
    for (ll f = 2; f*f <= m; f = f == 2 ? 3 : f + 2) {
      ll cur = 1;
      while (m % f == 0) {
        m /= f;
        cur *= f;
      }
      if (cur > 1 and cur > decomp[f].second)
        decomp[f] = {data[i].first % cur, cur};
    }
    if (m > 1 and m > decomp[m].second)
      decomp[m] = {data[i].first % m, m};
  }
  std::vector<pll> new_data;
  ll M = 1;
  for (auto &[f, cm] : decomp) {
      new_data.push_back(cm);
      M *= cm.second;
  }
  ll x = crt(new_data);
  for (int i = 0; i < data.size(); ++i)
    if (x % M != data[i].first % data[i].second)
      return {0, 0};
  return {x, M};
}
ll crt_test(std::vector<pll> &data) {
  if (data.size() <= 1)
    return std::__gcd(data[0].first, data[0].second) == 1;
  ll gC = std::__gcd(data[0].first, data[1].first);
  ll gM = std::__gcd(data[0].second, data[1].second);
  for (int i = 2; i < data.size(); ++i) {
    gC = std::__gcd(gC, data[i].first);
    gM = std::__gcd(gM, data[i].second);
  }
  return (gC % gM) == 0;
}
