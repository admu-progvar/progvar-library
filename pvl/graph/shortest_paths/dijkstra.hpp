#ifndef PVL_GRAPH_SHORTEST_PATHS_DIJKSTRA_HPP_
#define PVL_GRAPH_SHORTEST_PATHS_DIJKSTRA_HPP_ 1

#include <functional>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

#include "graph/graph.hpp"


namespace pvl {

using graph = graph_adj_list;

template <typename T>
T default_identity() { return T(0); }

template <typename T>
T default_add(T a, T b) { return a + b; }

template <typename T>
T default_mult(T a, T b) { return std::min(a, b); }

template <
  typename T,
  T (*e)() = default_identity,
  T (*add)(T, T) = default_add,
  T (*mult)(T, T) = default_mult
>
struct graph_dijkstra: public graph {
  std::vector<std::vector<std::pair<int, T>>> adj;
  std::vector<T> dist;
  graph_dijkstra(
    int n, bool directed = true
  ): graph(n, directed) {
    std::vector<std::vector<std::pair<int, T>>>(n).swap(adj);
  }
  void add_edge(int u, int v, T w) {
    adj[u].push_back({v, w});
    if (not directed)
      adj[v].push_back({u, w});
  }
  void dijkstra(int s, T inf) {
    std::vector<T>(n, inf).swap(dist);
    dist[s] = e();
    std::priority_queue<
      std::pair<T, int>,
      std::vector<std::pair<T, int>>,
      std::greater<std::pair<T, int>>
    > pq;
    pq.push({dist[s], s});
    while (!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();
      T lower_dist = mult(dist[u], d);
      if (d != lower_dist)  continue;
      dist[u] = lower_dist;
      for (auto [v, w] : adj[u]) {
        T new_dist = mult(dist[v], add(dist[u], w));
        if (dist[v] == new_dist)  continue;
        dist[v] = new_dist;
        pq.push({dist[v], v});
      }
    }
  }
};

}  // namespace pvl

#endif  // PVL_GRAPH_SHORTEST_PATHS_DIJKSTRA_HPP_
