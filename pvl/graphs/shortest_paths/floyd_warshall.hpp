#ifndef PVL_GRAPHS_SHORTEST_PATHS_FLOYD_WARSHALL_HPP_
#define PVL_GRAPHS_SHORTEST_PATHS_FLOYD_WARSHALL_HPP_ 1

#include "math/algebra.hpp"
#include "graphs/weighted_graphs.hpp"


namespace pvl {

template <
  typename T,
  T (*add)(T, T) = alg::add,
  T (*min)(T, T) = alg::min,
  T (*add_id)() = alg::add_id,
  T (*min_id)() = alg::min_id,
  T (*eq)(T, T) = alg::strict_eq
>
struct graph_floyd_marshall: public graph_adj_mat_weighted<
  T, add, add_id
> {
  using vT = std::vector<T>;
  using vvT = std::vector<vT>;
  vvT dists;
  graph_floyd_marshall(
    int n, bool directed = true
  ): graph_adj_mat_weighted<T, add, add_id>(n, directed) { }
  vvT& all_pairs_shortest_paths() {
    dists = this->mat;
    for (int u = 0; u < this->n; ++u)
      for (int v = 0; v < this->n; ++v) {
        if (u == v)
          dists[u][v] = add_id();
        else if (eq(dists[u][v], add_id()))
          dists[u][v] = min_id();
      }
    for (int k = 0; k < this->n; ++k)
      for (int u = 0; u < this->n; ++u)
        for (int v = 0; v < this->n; ++v)
          dists[u][v] = min(
            dists[u][v], add(dists[u][k], dists[k][v])
          );
    return dists;
  }
};

}  // namespace pvl

#endif  // PVL_GRAPHS_SHORTEST_PATHS_FLOYD_WARSHALL_HPP_
