struct graph {
  int n, *disc, *low, TIME;
  vi *adj, stk, articulation_points;
  std::set<ii> bridges;
  vvi comps;
  graph (int n) : n(n) {
    adj = new vi[n];
    disc = new int[n];
    low = new int[n]; }
  void add_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); }
  void _bridges_artics(int u, int p) {
    disc[u] = low[u] = TIME++;
    stk.push_back(u);
    int children = 0;
    bool has_low_child = false;
    for (int v : adj[u]) {
      if (disc[v] == -1) {
        _bridges_artics(v, u);
        children++;
        if (disc[u] < low[v])
          bridges.insert({std::min(u, v), std::max(u, v)});
        if (disc[u] <= low[v]) {
          has_low_child = true;
          comps.push_back({u});
          while (comps.back().back() != v and !stk.empty()) {
            comps.back().push_back(stk.back());
            stk.pop_back(); } }
        low[u] = std::min(low[u], low[v]);
      } else if (v != p)
        low[u] = std::min(low[u], disc[v]); }
    if ((p == -1 && children >= 2) ||
        (p != -1 && has_low_child))
      articulation_points.push_back(u); }
  void bridges_artics() {
    for (int u = 0; u < n; ++u)   disc[u] = -1;
    stk.clear();
    articulation_points.clear();
    bridges.clear();
    comps.clear();
    TIME = 0;
    for (int u = 0; u < n; ++u) if (disc[u] == -1)
      _bridges_artics(u, -1); } };
