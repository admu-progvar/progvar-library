#ifndef PVL_GRAPHS_TREE_TREE_DIAMETER_HPP_
#define PVL_GRAPHS_TREE_TREE_DIAMETER_HPP_ 1

#include "./base.hpp"
#include "./graphs/unweighted_graphs.hpp"
#include "./graphs/basic_traversal/bfs.hpp"


namespace pvl {

vi find_tree_diameter(const graph_adj_list &g) {
  /*
    Finds a diamter path of a tree g.

    Assumption: g is a tree.
  */
  bfs_data data_1 = bfs(g, 0);
  bfs_data data_2 = bfs(g, data_1.farthest);
  vi diameter;
  for (int u = data_2.farthest; u != -1; u = data_2.par[u])
    diameter.push_back(u);
  return diameter;
}

}  // namespace pvl

#endif  // PVL_GRAPHS_TREE_TREE_DIAMETER_HPP_
