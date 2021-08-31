bool sieve[LIM+1];// remember to sieve up to some LIM
vector<ll> primes;
//deterministic up to 2^64
ll good_bases[] = {2,325,9375,28178,450775,9780504,1795265022};
// remember mod_pow and mod_mult
bool witness(ll a,ll n) {
  ll t = 0, u = n-1;
  while (u % 2 ==0) {
    u >>= 1;
    t += 1; }
  ll xp = 1, xi = mod_pow(a,u,n);
  for (int i = 0; i < t; i++) {
    xp = xi;
    xi = mod_mult(xi, xi, n);
    if (xi == 1 && !(xp == 1 || xp == n-1)) return true; }
  return xi != 1; }
bool miller_rabin(ll n) {
  if (n <= 1)   return false;
  if (n == 2)   return true;
  if (n%2 == 0) return false;
  if (n <= LIM) return sieve[n];
  for (const ll& x : good_bases) {
    ll a = x % n;
    if (a == 0)       return true;
    if (witness(a,n)) return false; }
  return true; }
