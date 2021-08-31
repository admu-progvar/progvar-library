ll dp[G+1][N+1];
void solve_dp(int g, int k_L, int k_R, int n_L, int n_R) {
  /*
  For DP problems of the form $$dp(i,j) = min_{k \leq j}
  \{dp(i-1,k)+C(k,j)\}$$ where $C(k,j)$ is some cost function.
  */
  int n_M = (n_L+n_R)/2;
  dp[g][n_M] = INF;
  int best_k = -1;
  for (int k = k_L; k <= n_M && k <= k_R; k++)
    if (dp[g-1][k]+cost(k+1,n_M) < dp[g][n_M]) {
      dp[g][n_M] = dp[g-1][k]+cost(k+1,n_M);
      best_k = k; }
  if (n_L <= n_M-1)
    solve_dp(g, k_L, best_k, n_L, n_M-1);
  if (n_M+1 <= n_R)
    solve_dp(g, best_k, k_R, n_M+1, n_R); }
