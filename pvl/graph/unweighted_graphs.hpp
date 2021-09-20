#ifndef PVL_GRAPH_UNWEIGHTED_GRAPHS_HPP_
#define PVL_GRAPH_UNWEIGHTED_GRAPHS_HPP_ 1

#include <algorithm>
#include <utility>
#include <vector>
#include <set>


namespace pvl {

struct graph_adj_list {
  int n;
  bool directed;
  std::vector<std::vector<int>> adj;
  explicit graph_adj_list(
    int n, bool directed = false
  ): n(n), directed(directed) {
    std::vector<std::vector<int>>(n).swap(adj);
  }
  void add_edge(int u, int v) {
    adj[u].push_back(v);
    if (not directed)
      adj[v].push_back(u);
  }
};

struct graph_adj_mat {
  int n;
  bool directed;
  std::vector<std::vector<int>> mat;
  explicit graph_adj_mat(
    int n, bool directed = false
  ): n(n), directed(directed) {
    std::vector<std::vector<int>>(
        n, std::vector<int>(n, 0)
    ).swap(mat);
  }
  void add_edge(int u, int v) {
      mat[u][v]++;
      if (not directed)
          mat[v][u]++;
  }
};

struct graph_edge_list {
  int n;
  bool directed;
  std::set<std::pair<int, int> > edges;
  explicit graph_edge_list(
    int n, bool directed = false
  ): n(n), directed(directed) { }
  void add_edge(int u, int v) {
    if (directed)
      edges.insert({u, v});
    else
      edges.insert({std::min(u, v), std::max(u, v)});
  }
};

}  // namespace pvl

#endif  // PVL_GRAPH_UNWEIGHTED_GRAPHS_HPP_
