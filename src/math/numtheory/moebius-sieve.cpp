std::bitset<N> is; int mu[N];
void mobiusSieve() {
  for (int i = 1; i < N; ++i) mu[i] = 1;
  for (int i = 2; i < N; ++i) if (!is[i]) {
    for (int j = i; j < N; j += i) { is[j] = 1; mu[j] *= -1; }
    for (long long j = 1LL*i*i; j < N; j += i*i) mu[j] = 0; } }
