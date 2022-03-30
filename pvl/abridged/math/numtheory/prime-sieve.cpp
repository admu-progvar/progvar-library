bitset<N> isc; // #include <bitset>
vector<int> p;
void sieve() {
  for (int i = 2; i < N; i++) {
      if (!isc[i]) p.push_back(i);
      for (int j = 0; j < p.size() && i*p[j] < N; j++) {
          isc[i*p[j]] = 1;
          if (i%p[j] == 0) break; } } }
