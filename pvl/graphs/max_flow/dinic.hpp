#ifndef PVL_GRAPHS_MAX_FLOW_DINIC_HPP_
#define PVL_GRAPHS_MAX_FLOW_DINIC_HPP_ 1

#include <vector>
#include <queue>
#include <cassert>

#include "./math/constants.hpp"

typedef long long ll;


namespace pvl {

struct flow_network_dinic {
  struct edge {
    int u, v;
    ll c, f;
    edge(int u, int v, ll c) : u(u), v(v), c(c), f(0) {} };
  int n;
  std::vector<int> adj_ptr, par, dist;
  std::vector<std::vector<int>> adj;
  std::vector<edge> edges;
  explicit flow_network_dinic(int n) : n(n) {
    std::vector<std::vector<int>>(n).swap(adj);
    reset();
  }
  void reset() {
    std::vector<int>(n).swap(adj_ptr);
    std::vector<int>(n).swap(par);
    std::vector<int>(n).swap(dist);
    for (edge &e : edges)  e.f = 0;
  }
  void add_edge(int u, int v, ll c, bool bi = false) {
    adj[u].push_back(edges.size());
    edges.push_back(edge(u, v, c));
    adj[v].push_back(edges.size());
    edges.push_back(edge(v, u, (bi ? c : 0LL))); }
  ll res(const edge &e) { return e.c - e.f; }
  bool make_level_graph(int s, int t) {
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
  bool dfs(int u, int t) {
    if (u == t)   return true;
    for (int &ii = adj_ptr[u]; ii < adj[u].size(); ++ii) {
      int i = adj[u][ii];
      edge &e = edges[i];
      if (is_next(u, e.v) and res(e) > 0 and dfs(e.v, t)) {
        par[e.v] = i;
        return true; } }
    return false; }
  bool aug_path(int s, int t) {
    for (int u = 0; u < n; ++u) par[u] = -1;
    return dfs(s, t); }
  ll calc_max_flow(int s, int t) {
    ll total_flow = 0;
    while (make_level_graph(s, t)) {
      for (int u = 0; u < n; ++u)   adj_ptr[u] = 0;
      while (aug_path(s, t)) {
        ll flow = pvl::LL_INF;
        for (int i = par[t]; i != -1; i = par[edges[i].u])
          flow = std::min(flow, res(edges[i]));
        for (int i = par[t]; i != -1; i = par[edges[i].u]) {
          edges[i].f   += flow;
          edges[i^1].f -= flow; }
        total_flow += flow; } }
    return total_flow; }
  std::vector<bool> min_cut(int s, int t) {
    calc_max_flow(s, t);
    assert(!make_level_graph(s, t));
    std::vector<bool> cut_mem(n);
    for (int u = 0; u < n; ++u)
      cut_mem[u] = (dist[u] != -1);
    return cut_mem; } };

}  // namespace pvl

#endif  // PVL_GRAPHS_MAX_FLOW_DINIC_HPP_
