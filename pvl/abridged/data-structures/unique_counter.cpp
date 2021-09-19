struct UniqueCounter {
  int *B; std::map<int, int> last; LeqCounter *leq_cnt;
  UniqueCounter(int *ar, int n) { // 0-index A[i]
    B = new int[n+1];
    B[0] = 0;
    for (int i = 1; i <= n; ++i) {
      B[i] = last[ar[i-1]];
      last[ar[i-1]] = i; }
    leq_cnt = new LeqCounter(B, n+1); }
  int count(int l, int r) {
    return leq_cnt->count(l+1, r+1, l); } };
