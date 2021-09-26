struct flow_network {
  struct edge { int v, nxt, cap;
    edge(int _v, int _cap, int _nxt)
      : v(_v), nxt(_nxt), cap(_cap) { } };
  int n; vi head, curh, dist; vector<edge> e, e_store;
  flow_network(int _n) : n(_n), curh(vi(n)), head(vi(n)) {
    for (int u = 0; u < n; ++u) head[u] = -1; }
  void reset() { e = e_store; }
  void add_edge(int u, int v, int uv, int vu=0) {
    e.push_back(edge(v,uv,head[u])); head[u]=e.size()-1;
    e.push_back(edge(u,vu,head[v])); head[v]=e.size()-1; }
  int augment(int v, int t, int f) {
    if (v == t) return f;
    for (int &i = curh[v]; i != -1; i = e[i].nxt)
      if (e[i].cap > 0 && dist[e[i].v] + 1 == dist[v]) {
        int ret = augment(e[i].v, t, std::min(f, e[i].cap));
        if (ret > 0)
          return (e[i].cap -= ret, e[i^1].cap += ret, ret); }
    return 0; }
  int calc_max_flow(int s, int t, bool res=true) {
    e_store = e;
    int f = 0, x;
    while (true) {
      for (int u = 0; u < n; ++u) dist[u] -1;
      dist[t] = 0;
      std::queue<int> q;  q.push(t);
      while (!q.empty()) {
        int v = q.front();  q.pop();
        for (int i = head[v]; i != -1; i = e[i].nxt)
          if (e[i^1].cap > 0 && dist[e[i].v] == -1) {
            dist[e[i].v] = dist[v] + 1;
            q.push(e[i].v); } }
      if (dist[s] == -1) break;
      for (int u = 0; u < n; ++u) curh[u] = head[u];
      while ((x = augment(s, t, INF)) != 0) f += x; }
    if (res) reset();
    return f; } };
struct gomory_hu_tree {
  int n; vii par; vvi cap;
  gomory_hu_tree(flow_network &g): n(g.n) {
    vii(n, ii(0, 0)).swap(par);
    vvi(n, vi(n, -1)).swap(cap);
    for (int s = 1; s < n; ++s) {
      par[s].second = g.calc_max_flow(s, par[s].first, false);
      vi vis(n, 0), same(n, 0);
      std::queue<int> q;  q.push(s);
      vis[s] = 1;
      while (!q.empty()) {
        int v = q.front();  q.pop();
        same[v] = true;
        for (int i = g.head[v]; i != -1; i = g.e[i].nxt)
          if (g.e[i].cap > 0 && vis[g.e[i].v] == 0) {
            vis[g.e[i].v] = 1;
            q.push(g.e[i].v); } }
      for (int i = s+1; i < n; ++i)
        if (par[i].first == par[s].first && same[i])
          par[i].first = s;
      g.reset(); }
    for (int i = 0; i < n; ++i) {
      int mn = INF, cur = i;
      while (true) {
        cap[cur][i] = mn;
        if (cur == 0) break;
        mn = std::min(mn, par[cur].second);
        cur = par[cur].first; } } }
  int calc_max_flow(int s, int t) {
    int cur = INF, at = s;
    while (cap[at][t] == -1) {
      cur = std::min(cur, par[at].second);
      at = par[at].first; }
    return std::min(cur, cap[at][t]); } }
