#ifndef PVL_GRAPHS_MST_PRIM_HPP_
#define PVL_GRAPHS_MST_PRIM_HPP_ 1

#include <queue>
#include <vector>
#include <utility>
#include "graphs/weighted_graphs.hpp"

namespace pvl {

graph_edge_list_weighted<int> prim(
    const graph_adj_list_weighted<int>& g, int s = 0) {
  graph_edge_list_weighted<int> res(0);
  using Tii = std::pair<int,
                        graph_edge_list_weighted<int>::ii>;
  std::priority_queue<Tii, std::vector<Tii>,
                      std::greater<Tii>> pq;
  std::vector<bool> vis(g.adj.size());
  vis[s] = true;
  for (auto &[v, w] : g.adj[s])
    if (!vis[v])
      pq.push({w, {s, v}});
  while (!pq.empty()) {
    auto [w, ii] = pq.top();
    auto [v, u] = ii;
    pq.pop();
    if (vis[u]) continue;
    vis[u] = true;
    res.add_edge(v, u, w);
    for (auto &[v, w] : g.adj[u])
      if (!vis[v])
        pq.push({w, {u, v}});
  }
  return res;
}

}  // namespace pvl

#endif  // PVL_GRAPHS_MST_PRIM_HPP_
