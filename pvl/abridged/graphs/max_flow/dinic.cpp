struct edge {
  int u, v;
  ll c, f;
  edge(int u, int v, ll c) : u(u), v(v), c(c), f(0) {} };
struct flow_network {
  int n, s, t, *adj_ptr, *par, *dist;
  std::vector<edge> edges;
  std::vector<int> *adj;
  flow_network(int n, int s, int t) : n(n), s(s), t(t) {
    adj     = new std::vector<int>[n];
    adj_ptr = new int[n];
    par  = new int[n];
    dist = new int[n]; }
  void add_edge(int u, int v, ll c, bool bi=false) {
    adj[u].push_back(edges.size());
    edges.push_back(edge(u, v, c));
    adj[v].push_back(edges.size());
    edges.push_back(edge(v, u, (bi ? c : 0LL))); }
  ll res(edge &e) { return e.c - e.f; }
  bool make_level_graph() {
    for (int u = 0; u < n; ++u)   dist[u] = -1;
    dist[s] = 0;
    std::queue<int> q;     q.push(s);
    while (!q.empty()) {
      int u = q.front();  q.pop();
      for (int i : adj[u]) {
        edge &e = edges[i];
        if (dist[e.v] < 0 and res(e)) {
          dist[e.v] = dist[u] + 1;
          q.push(e.v); } } }
    return dist[t] != -1; }
  bool is_next(int u, int v) {
    return dist[v] == dist[u] + 1; }
  bool dfs(int u) {
    if (u == t)   return true;
    for (int &ii = adj_ptr[u]; ii < adj[u].size(); ++ii) {
      int i = adj[u][ii];
      edge &e = edges[i];
      if (is_next(u, e.v) and res(e) > 0 and dfs(e.v)) {
        par[e.v] = i;
        return true; } }
    return false; }
  bool aug_path() {
    for (int u = 0; u < n; ++u) par[u] = -1;
    return dfs(s); }
  ll calc_max_flow() {
    ll total_flow = 0;
    while (make_level_graph()) {
      for (int u = 0; u < n; ++u)   adj_ptr[u] = 0;
      while (aug_path()) {
        ll flow = INF;
        for (int i = par[t]; i != -1; i = par[edges[i].u])
          flow = std::min(flow, res(edges[i]));
        for (int i = par[t]; i != -1; i = par[edges[i].u]) {
          edges[i].f   += flow;
          edges[i^1].f -= flow; }
        total_flow += flow; } }
    return total_flow; } };
