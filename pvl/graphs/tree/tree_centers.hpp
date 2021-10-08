#ifndef PVL_GRAPHS_TREE_TREE_CENTERS_HPP_
#define PVL_GRAPHS_TREE_TREE_CENTERS_HPP_ 1

#include "base.hpp"
#include "graphs/unweighted_graphs.hpp"
#include "graphs/tree/tree_diameter.hpp"


namespace pvl {

vi find_tree_centers(const graph_adj_list &g) {
  /*
    Finds the center or centers of a tree g.

    Assumption: g is a tree.
  */
  vi diam = find_tree_diameter(g);
  int size = diam.size();
  vi centers(1, diam[size / 2]);
  if (size % 2 == 0)  centers.push_back(diam[size/2 - 1]);
  return centers;
}

}  // namespace pvl

#endif  // PVL_GRAPHS_TREE_TREE_CENTERS_HPP_
