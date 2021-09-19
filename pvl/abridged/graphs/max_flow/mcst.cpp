struct edge {
  int u, v; ll cost, cap, flow;
  edge(int u, int v, ll cap, ll cost) :
    u(u), v(v), cap(cap), cost(cost), flow(0) {} };
struct flow_network {
  int n, s, t, *par, *in_queue, *num_vis; ll *dist, *pot;
  std::vector<edge> edges;
  std::vector<int> *adj;
  std::map<std::pair<int, int>, std::vector<int> > edge_idx;
  flow_network(int n, int s, int t) : n(n), s(s), t(t) {
    adj = new std::vector<int>[n];
    par = new int[n];
    in_queue = new int[n];
    num_vis = new int[n];
    dist = new ll[n];
    pot  = new ll[n];
    for (int u = 0; u < n; ++u) pot[u] = 0; }
  void add_edge(int u, int v, ll cap, ll cost) {
    adj[u].push_back(edges.size());
    edge_idx[{u, v}].push_back(edges.size());
    edges.push_back(edge(u, v, cap, cost));
    adj[v].push_back(edges.size());
    edge_idx[{v, u}].push_back(edges.size());
    edges.push_back(edge(v, u, 0LL, -cost)); }
  ll get_flow(int u, int v) {
    ll f = 0;
    for (int i : edge_idx[{u, v}]) f += edges[i].flow;
    return f; }
  ll res(edge &e) { return e.cap - e.flow; }
  void bellman_ford() {
    for (int u = 0; u < n; ++u) pot[u] = INF;
    pot[s] = 0;
    for (int it = 0; it < n-1; ++it)
      for (auto e : edges)
        if (res(e) > 0)
          pot[e.v] = std::min(pot[e.v], pot[e.u] + e.cost); }
  bool spfa () {
    std::queue<int> q;  q.push(s);
    while (not q.empty()) {
      int u = q.front();  q.pop();  in_queue[u] = 0;
      if (++num_vis[u] >= n) {
        dist[u] = -INF;
        return false; }
      for (int i : adj[u]) {
        edge e = edges[i];
        if (res(e) <= 0)  continue;
        ll nd = dist[u] + e.cost + pot[u] - pot[e.v];
        if (dist[e.v] > nd) {
          dist[e.v] = nd;
          par[e.v] = i;
          if (not in_queue[e.v]) {
            q.push(e.v);
            in_queue[e.v] = 1; } } } }
    return dist[t] != INF; }
  bool aug_path() {
    for (int u = 0; u < n; ++u) {
      par[u]      = -1;
      in_queue[u] = 0;
      num_vis[u]  = 0;
      dist[u]     = INF; }
    dist[s] = 0;
    in_queue[s] = 1;
    return spfa();
  }
  pll calc_max_flow(bool do_bellman_ford=false) {
    ll total_cost = 0, total_flow = 0;
    if (do_bellman_ford)
      bellman_ford();
    while (aug_path()) {
      ll f = INF;
      for (int i = par[t]; i != -1; i = par[edges[i].u])
        f = std::min(f, res(edges[i]));
      for (int i = par[t]; i != -1; i = par[edges[i].u]) {
        edges[i].flow   += f;
        edges[i^1].flow -= f; }
      total_cost += f * (dist[t] + pot[t] - pot[s]);
      total_flow += f;
      for (int u = 0; u < n; ++u)
        if (par[u] != -1) pot[u] += dist[u]; }
    return {total_cost, total_flow}; } };
