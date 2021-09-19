LL f[P], lid; // P: biggest prime
LL lucas(LL n, LL k, int p) {
    if (k == 0) return 1;
    if (n < p && k < p) {
        if (lid != p) {
            lid = p; f[0] = 1;
            for (int i = 0; i < p; ++i) f[i]=f[i-1]*i%p;
        }
        return f[n] * modpow(f[n-k]*f[k]%p, p-2, p) % p;}
    return lucas(n/p,k/p,p) * lucas(n%p,k%p,p) % p; }
