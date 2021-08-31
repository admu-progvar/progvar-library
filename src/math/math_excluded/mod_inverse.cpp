ll mod_inverse(ll x, ll mod) {
  return fast_exp(x, mod-2, mod);
}
