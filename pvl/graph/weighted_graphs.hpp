#ifndef PVL_GRAPH_WEIGHTED_GRAPHS_HPP_
#define PVL_GRAPH_WEIGHTED_GRAPHS_HPP_ 1

#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>

#include "math/algebra.hpp"


namespace pvl {

template <typename T>
struct graph_adj_list_weighted {
  using vviT = std::vector<std::vector<std::pair<int, T>>>;
  int n;
  bool directed;
  vviT adj;
  explicit graph_adj_list_weighted(
    int n, bool directed = false
  ): n(n), directed(directed) {
    vviT(n).swap(adj);
  }
  void add_edge(int u, int v, T w) {
    adj[u].push_back({v, w});
    if (not directed)
      adj[v].push_back({u, w});
  }
};

template <
  typename T,
  T (*add)(T, T) = alg::add,
  T (*add_id)() = alg::add_id
>
struct graph_adj_mat_weighted {
  using vT = std::vector<T>;
  using vvT = std::vector<vT>;
  int n;
  bool directed;
  vvT mat;
  explicit graph_adj_mat_weighted(
    int n, bool directed = false
  ): n(n), directed(directed) {
    vvT(n, vT(n, add_id())).swap(mat);
  }
  void add_edge(int u, int v, T w) {
      mat[u][v] = add(mat[u][v], w);
      if (not directed)
          mat[v][u] = add(mat[v][u], w);
  }
};

template <
  typename T,
  T (*add)(T, T) = alg::add,
  T (*add_id)() = alg::add_id
>
struct graph_edge_list_weighted {
  using ii = std::pair<int, int>;
  int n;
  bool directed;
  std::set<ii> edges;
  std::map<ii, T> weight;
  explicit graph_edge_list_weighted(
    int n, bool directed = false
  ): n(n), directed(directed) { }
  void add_edge(int u, int v, T w) {
    ii edge;
    if (directed)
      edge = {u, v};
    else
      edge = {std::min(u, v), std::max(u, v)};
    edges.insert(edge);
    if (weight.find(edge) == weight.end())
      weight[edge] = add_id();
    else
      weight[edge] = add(weight[edge], w);
  }
};

}  // namespace pvl

#endif  // PVL_GRAPH_WEIGHTED_GRAPHS_HPP_
