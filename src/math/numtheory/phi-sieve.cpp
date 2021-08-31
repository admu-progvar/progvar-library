std::bitset<N> is; int phi[N];
void phiSieve() {
  for (int i = 1; i < N; ++i) phi[i] = i;
  for (int i = 2; i < N; ++i) if (!is[i]) {
    for (int j = i; j < N; j += i) {
      phi[j] -= phi[j] / i; is[j] = true; } } }
