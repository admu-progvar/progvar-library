struct graph {
  int n, logn, *par, *dep, *first, *lg, **spt;
  vi *adj, euler; // spt size should be ~ 2n
  graph(int n, int logn=20) : n(n), logn(logn) {
    adj = new vi[n];
    par = new int[n];
    dep = new int[n];
    first = new int[n]; }
  void add_edge(int u, int v) {
    adj[u].push_back(v); adj[v].push_back(u); }
  void dfs(int u, int p, int d) {
    dep[u] = d; par[u] = p;
    first[u] = euler.size();
    euler.push_back(u);
    for (int v : adj[u])
      if (v != p) {
        dfs(v, u, d+1);
        euler.push_back(u); } }
  void prep_lca(int root=0) {
    dfs(root, root, 0);
    int en = euler.size();
    lg = new int[en+1];
    lg[0] = lg[1] = 0;
    for (int i = 2; i <= en; ++i)
      lg[i] = lg[i >> 1] + 1;
    spt = new int*[en];
    for (int i = 0; i < en; ++i) {
      spt[i] = new int[lg[en]];
      spt[i][0] = euler[i]; }
    for (int k = 0; (2 << k) <= en; ++k)
      for (int i = 0; i + (2 << k) <= en; ++i)
        if (dep[spt[i][k]] < dep[spt[i+(1<<k)][k]])
          spt[i][k+1] = spt[i][k];
        else
          spt[i][k+1] = spt[i+(1<<k)][k]; }
  int lca(int u, int v) {
    int a = first[u], b = first[v];
    if (a > b)    std::swap(a, b);
    int k = lg[b-a+1], ba = b - (1 << k) + 1;
    if (dep[spt[a][k]] < dep[spt[ba][k]]) return spt[a][k];
    return spt[ba][k]; } };
