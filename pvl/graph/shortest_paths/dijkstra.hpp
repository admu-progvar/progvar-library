#ifndef PVL_GRAPH_SHORTEST_PATHS_DIJKSTRA_HPP_
#define PVL_GRAPH_SHORTEST_PATHS_DIJKSTRA_HPP_ 1

#include <utility>
#include <vector>
#include <queue>

#include "math/algebra.hpp"
#include "graph/weighted_graphs.hpp"


namespace pvl {

template <
  typename T,
  T (*add)(T, T) = alg::add,
  T (*min)(T, T) = alg::min,
  T (*add_id)() = alg::add_id,
  T (*min_id)() = alg::min_id,
  T (*eq)(T, T) = alg::strict_eq
>
struct graph_dijkstra: public graph_adj_list_weighted<T> {
  using vT = std::vector<T>;
  using vvT = std::vector<vT>;
  using Ti = std::pair<T, int>;
  using vTi = std::vector<Ti>;
  vT dist;  // dists from latest source node
  vvT dists;
  graph_dijkstra(
    int n, bool directed = true
  ): graph_adj_list_weighted<T>(n, directed) { }
  std::vector<T>& single_source_shortest_paths(int s) {
    vT(this->n, min_id()).swap(dist);
    dist[s] = add_id();
    std::priority_queue<Ti, vTi, std::greater<Ti>> pq;
    pq.push({dist[s], s});
    while (!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();
      T lower_dist = min(dist[u], d);
      if (!eq(d, lower_dist))  continue;
      dist[u] = lower_dist;
      for (auto [v, w] : this->adj[u]) {
        T new_dist = min(dist[v], add(dist[u], w));
        if (eq(dist[v], new_dist))  continue;
        dist[v] = new_dist;
        pq.push({dist[v], v});
      }
    }
    return dist;
  }
  vvT& all_pairs_shortest_paths() {
    vvT(this->n, vT(this->n, min_id())).swap(dists);
    for (int u = 0; u < this->n; ++u)
      dists[u] = single_source_shortest_paths(u);
    return dists;
  }
};

}  // namespace pvl

#endif  // PVL_GRAPH_SHORTEST_PATHS_DIJKSTRA_HPP_
