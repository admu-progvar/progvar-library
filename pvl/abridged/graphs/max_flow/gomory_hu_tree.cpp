#include "dinic.cpp"
struct gomory_hu_tree {
  int n;
  std::vector<int> dep;
  std::vector<std::pair<int, ll>> par;
  explicit gomory_hu_tree(flow_network_dinic &g) : n(g.n) {
    std::vector<std::pair<int, ll>>(n, {0, 0LL}).swap(par);
    std::vector<int>(n, 0).swap(dep);
    std::vector<int> temp_par(n, 0);
    for (int u = 1; u < n; ++u) {
      g.reset();
      ll flow = g.calc_max_flow(u, temp_par[u]);
      std::vector<bool> cut_mem = g.min_cut(u, temp_par[u]);
      for (int v = u+1; v < n; ++v)
        if (cut_mem[u] == cut_mem[v]
            and temp_par[u] == temp_par[v])
          temp_par[v] = u;
      add_edge(temp_par[u], u, flow); } }
  void add_edge(int u, int v, ll w) {
    par[v] = {u, w}; dep[v] = dep[u] + 1; }
  ll calc_max_flow(int s, int t) {
    ll ans = pvl::LL_INF;
    while (dep[s] > dep[t]) {
      ans = std::min(ans, par[s].second); s = par[s].first; }
    while (dep[s] < dep[t]) {
      ans = std::min(ans, par[t].second); t = par[t].first; }
    while (s != t) {
      ans = std::min(ans, par[s].second); s = par[s].first;
      ans = std::min(ans, par[t].second); t = par[t].first; }
    return ans; } };
