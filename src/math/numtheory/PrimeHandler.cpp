class prime_handler {
  static const ll N = (1<<20);
  static const ll BIG_N = (1LL<<60LL);
  ll mod_mult(ll a, ll b, ll MOD) {
    if(b==0) return 0;
    if(b&1) return (a+mod_mult(a,b-1,MOD))%MOD;
    else return mod_mult((a+a)%MOD,b/2,MOD); }
  ll mod_pow(ll base, ll exp, ll MOD) {
    if(exp==0) return 1;
    if(exp&1) return mod_mult(base,mod_pow(base,exp-1,MOD),MOD);
    else return mod_pow(mod_mult(base,base,MOD),exp/2,MOD); }
  vector<ll> good_bases = {2, 325, 9375, 28178, 450775,
                           9780504, 1795265022};
  bool sieve[N+1];
  vector<ll> primes;
  //deterministic up to 2^64
  bool witness(ll a,ll n) {
    ll t = 0, u = n-1;
    while(u % 2 == 0) { u >>= 1; t += 1; }
    ll xp = 1, xi = mod_pow(a,u,n);
    for(int i = 0; i < t; i++) {
      xp = xi;
      xi = mod_mult(xi,xi,n);
      if(xi==1 && !(xp == 1 || xp == n-1)) return true ; }
    if(xi!=1) return true;
    else return false; }
public:
  prime_handler() {
    memset(sieve,true,sizeof sieve);
    sieve[0] = sieve[1] = false;
    for (ll p = 2; p <= N; p++)
      if(sieve[p]) {
        if(p!=2)
          primes.push_back(p);
        for(ll k = p*p; k <=N; k+=p)
          sieve[k] = false; } }
  bool is_prime(ll n) {
    if(n<=1) return false;
    if(n==2) return true;
    if(n%2==0) return false;
    if(n <= N) return sieve[n];
    for( const ll& x : good_bases) {
      ll a = x;
      a = a%n;
      if(a==0) return true;
      if(witness(a,n)) return false; }
    return true; }
  ll next_prime(ll n, ll step=1) {
    for(ll x = n; x >= 1; x += step)
      if(is_prime(x)) return x;
    return -1; }
  ll next_prime(double d, ll step=1) {
    return next_prime((ll)(floor(d+1e-7)+(step > 0)), step); }
  ll kth_prime(int k) { return primes[k-1]; } };
