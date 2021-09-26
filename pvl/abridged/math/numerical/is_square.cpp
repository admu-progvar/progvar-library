long long M;
void init_is_square() {
  for (int i = 0; i < 64; ++i) M |= 1ULL << (63-(i*i)%64); }
inline bool is_square(ll x) {
  if (x == 0) return true; // XXX
  if ((M << x) >= 0) return false;
  int c = std::__builtin_ctz(x);
  if (c & 1) return false;
  x >>= c;
  if ((x&7) - 1) return false;
  ll r = std::sqrt(x);
  return r*r == x; }
