#include "mod_pow.cpp"
ll primitive_root(ll m) {
  std::vector<ll> div;
  for (ll i = 1; i*i <= m-1; i++) {
    if ((m-1) % i == 0) {
      if (i < m) div.push_back(i);
      if (m/i < m) div.push_back(m/i); } }
  for (int x = 2; x < m; ++x) {
    bool ok = true;
    for (int d : div) if (mod_pow<ll>(x, d, m) == 1) {
      ok = false; break; }
    if (ok) return x; }
  return -1; }
