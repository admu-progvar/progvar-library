typedef std::vector<double> vd;
double min_mean_cycle(graph &g) {
  double mn = INF;
  std::vector<vd> dp(g.n+1, vd(g.n, mn));
  dp[0][0] = 0;
  for (int k = 1; k <= g.n; ++k)
    for (int u = 0; u < g.n; ++u)
      for (auto &[v, w]: g.adj[u])
        dp[k][v] = std::min(ar[k][v], dp[k-1][u] + w);
  for (int k = 0; k < g.n; ++k) {
    double mx = -INF;
    for (int u = 0; u < g.n; ++u)
      mx = std::max(mx, (dp[g.n][u] - dp[k][u]) / (g.n - k));
    mn = std::min(mn, mx);  }
  return mn;  }
