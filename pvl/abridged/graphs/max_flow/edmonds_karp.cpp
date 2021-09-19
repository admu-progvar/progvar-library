struct flow_network {
  int n, s, t, *par, **c, **f;
  vi *adj;
  flow_network(int n, int s, int t) : n(n), s(s), t(t) {
    adj = new std::vector<int>[n];
    par = new int[n];
    c = new int*[n];
    f = new int*[n];
    for (int i = 0; i < n; ++i) {
      c[i] = new int[n];
      f[i] = new int[n];
      for (int j = 0; j < n; ++j)
        c[i][j] = f[i][j] = 0; } }
  void add_edge(int u, int v, int w) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    c[u][v] += w; }
  int res(int i, int j) { return c[i][j] - f[i][j]; }
  bool bfs() {
    std::queue<int> q;
    q.push(this->s);
    while (!q.empty()) {
      int u = q.front();  q.pop();
      for (int v : adj[u]) {
        if (res(u, v) > 0 and par[v] == -1) {
          par[v] = u;
          if (v == this->t) return true;
          q.push(v); } } }
    return false; }
  bool aug_path() {
    for (int u = 0; u < n; ++u) par[u] = -1;
    par[s] = s;
    return bfs(); }
  int calc_max_flow() {
    int ans = 0;
    while (aug_path()) {
      int flow = INF;
      for (int u = t; u != s; u = par[u])
        flow = std::min(flow, res(par[u], u));
      for (int u = t; u != s; u = par[u])
        f[par[u]][u] += flow, f[u][par[u]] -= flow;
      ans += flow; }
    return ans; } };
