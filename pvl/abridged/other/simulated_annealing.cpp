double curtime() {
  return static_cast<double>(clock()) / CLOCKS_PER_SEC; }
int simulated_annealing(int n, double seconds) {
  default_random_engine rng;
  uniform_real_distribution<double> randfloat(0.0, 1.0);
  uniform_int_distribution<int> randint(0, n - 2);
  // random initial solution
  vi sol(n);
  for (int i = 0; i < n; ++i) sol[i] = i + 1;
  std::random_shuffle(sol.begin(), sol.end());
  // initialize score
  int score = 0;
  for (int i = 1; i < n; ++i)
    score += std::abs(sol[i] - sol[i-1]);
  int iters = 0;
  double T0 = 100.0, T1 = 0.001,
      progress = 0, temp = T0,
      starttime = curtime();
  while (true) {
    if (!(iters & ((1 << 4) - 1))) {
      progress = (curtime() - starttime) / seconds;
      temp = T0 * std::pow(T1 / T0, progress);
      if (progress > 1.0) break; }
    // random mutation
    int a = std::randint(rng);
    // compute delta for mutation
    int delta = 0;
    if (a > 0) delta += std::abs(sol[a+1] - sol[a-1])
                      - std::abs(sol[a] - sol[a-1]);
    if (a+2 < n) delta += std::abs(sol[a] - sol[a+2])
                        - std::abs(sol[a+1] - sol[a+2]);
    // maybe apply mutation
    if (delta >= 0 || randfloat(rng) < exp(delta / temp)) {
      std::swap(sol[a], sol[a+1]);
      score += delta;
      // if (score >= target) return;
    }
    iters++; }
  return score; }
