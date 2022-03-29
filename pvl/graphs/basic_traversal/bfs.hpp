#ifndef PVL_GRAPHS_BASIC_TRAVERSAL_BFS_HPP_
#define PVL_GRAPHS_BASIC_TRAVERSAL_BFS_HPP_ 1

#include <queue>

#include "./base.hpp"
#include "./math/constants.hpp"
#include "./graphs/unweighted_graphs.hpp"


namespace pvl {

struct bfs_data {
  vi vis, par;
  int farthest = -1;
  explicit bfs_data(int n) : vis(vi(n, 0)), par(vi(n, -1)) {}
};

bfs_data bfs(const graph_adj_list &g, int u) {
  bfs_data data(g.n);
  std::queue<int> q;  q.push(u);
  data.vis[u] = 1;
  while (!q.empty()) {
    u = q.front();  q.pop();
    for (int v : g.adj[u]) {
      if (not data.vis[v]) {
        data.vis[v] = 1;  data.par[v] = u;
        q.push(v); } } }
  data.farthest = u;
  return data;
}

}  // namespace pvl

#endif  // PVL_GRAPHS_BASIC_TRAVERSAL_BFS_HPP_
