#define MAXN 5000
int dist[MAXN+1], q[MAXN+1];
#define dist(v) dist[v == -1 ? MAXN : v]
struct bipartite_graph {
  int n, m, *L, *R; vi *adj;
  bipartite_graph(int n, int m) : n(n), m(m),
    L(new int[n]), R(new int[m]), adj(new vi[n]) {}
  ~bipartite_graph() { delete[] adj; delete[] L; delete[] R; }
  void add_edge(int u, int v) { adj[u].push_back(v); }
  bool bfs() {
    int l = 0, r = 0;
    for (int v = 0; v < n; ++v)
      if(L[v] == -1) dist(v) = 0, q[r++] = v;
      else dist(v) = INF;
    dist(-1) = INF;
    while(l < r) {
      int v = q[l++];
      if(dist(v) < dist(-1))
        for (int u : adj[v])
          if(dist(R[u]) == INF) {
            dist(R[u]) = dist(v) + 1;
            q[r++] = R[u];  } }
    return dist(-1) != INF; }
  bool dfs(int v) {
    if(v != -1) {
      for (int u : adj[v])
        if(dist(R[u]) == dist(v) + 1)
          if(dfs(R[u])) { R[u] = v; L[v] = u; return true; }
      dist(v) = INF;
      return false; }
    return true; }
  int maximum_matching() {
    int matching = 0;
    for (int u = 0; u < n; ++u)
      L[u] = R[u] = -1;
    while(bfs())
      for (int u = 0; u < n; ++u)
        matching += L[u] == -1 && dfs(u);
    return matching; } };
