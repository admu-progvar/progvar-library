std::bitset<N> is; // #include <bitset>
int pr[N], primes = 0;
void sieve() {
  is[2] = true; pr[primes++] = 2;
  for (int i = 3; i < N; i += 2) is[i] = 1;
  for (int i = 3; i*i < N; i += 2)
    if (is[i])
      for (int j = i*i; j < N; j += i)
        is[j]= 0;
  for (int i = 3; i < N; i += 2)
    if (is[i])
      pr[primes++] = i; }
