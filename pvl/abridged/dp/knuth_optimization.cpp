// opt[i][j] is the optimal split point between i and j
int dp[N][N], opt[N][N];
int cost(int i, int j) { /*...*/ }
int knuth_dp_solve() {
  for (int i = 0; i < N; i++)
    dp[i][i] = /*...*/, opt[i][i] = i;
  for (int i = N-2; i >= 0; --i)
    for (int j = i+1; j < N; ++j) {
      int mn = INF, c = cost(i, j);
      for (int k=opt[i][j-1]; k<=min(j-1,opt[i+1][j]); ++k) {
        int cur = dp[i][k] + dp[k+1][j] + c;
        if (cur < mn) mn = cur, opt[i][j] = k; }
      dp[i][j] = mn; } }
