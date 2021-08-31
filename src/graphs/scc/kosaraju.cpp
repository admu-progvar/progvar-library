struct kosaraju_graph {
  int n, *vis;
  vi **adj;
  std::vector<vi> sccs;
  kosaraju_graph(int n) {
    this->n = n;
    vis = new int[n];
    adj = new vi*[2];
    for (int dir = 0; dir < 2; ++dir)
      adj[dir] = new vi[n]; }
  void add_edge(int u, int v) {
    adj[0][u].push_back(v);
    adj[1][v].push_back(u); }
  void dfs(int u, int p, int dir, vi &topo) {
    vis[u] = 1;
    for (int v : adj[dir][u])
      if (!vis[v] && v != p) dfs(v, u, dir, topo);
    topo.push_back(u); }
  void kosaraju() {
    vi topo;
    for (int u = 0; u < n; ++u)  vis[u] = 0;
    for (int u = 0; u < n; ++u) if(!vis[u]) dfs(u, -1, 0, topo);
    for (int u = 0; u < n; ++u)  vis[u] = 0;
    for (int i = n-1; i >= 0; --i) {
      if (!vis[topo[i]]) {
        sccs.push_back({});
        dfs(topo[i], -1, 1, sccs.back()); } } } };
