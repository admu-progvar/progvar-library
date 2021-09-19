struct graph {
  int n, logn, *dep, **par;
  std::vector<int> *adj;
  graph(int n, int logn=20) : n(n), logn(logn) {
    adj = new std::vector<int>[n];
    dep = new int[n];
    par = new int*[n];
    for (int i = 0; i < n; ++i) par[i] = new int[logn]; }
  void dfs(int u, int p, int d) {
    dep[u] = d;
    par[u][0] = p;
    for (int v : adj[u])
      if (v != p) dfs(v, u, d+1); }
  int ascend(int u, int k) {
    for (int i = 0; i < logn; ++i)
      if (k & (1 << i)) u = par[u][i];
    return u; }
  int lca(int u, int v) {
    if (dep[u] > dep[v])  u = ascend(u, dep[u] - dep[v]);
    if (dep[v] > dep[u])  v = ascend(v, dep[v] - dep[u]);
    if (u == v)           return u;
    for (int k = logn-1; k >= 0; --k) {
      if (par[u][k] != par[v][k]) {
        u = par[u][k];  v = par[v][k]; } }
    return par[u][0]; }
  bool is_anc(int u, int v) {
    if (dep[u] < dep[v]) std::swap(u, v);
    return ascend(u, dep[u] - dep[v]) == v; }
  void prep_lca(int root=0) {
    dfs(root, root, 0);
    for (int k = 1; k < logn; ++k)
      for (int u = 0; u < n; ++u)
        par[u][k] = par[par[u][k-1]][k-1]; } };
