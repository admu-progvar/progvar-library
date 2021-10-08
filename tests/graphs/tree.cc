#include <vector>
#include <algorithm>
#include <ctime>
#include <random>

#include <gtest/gtest.h>
#include "../pvl/base.hpp"
#include "../pvl/graphs/tree/tree_diameter.hpp"
#include "../pvl/graphs/tree/tree_centers.hpp"


pvl::vi random_permutation(int n) {
  pvl::vi nodes(n);
  for (int u = 0; u < n; ++u) nodes[u] = u;
  std::random_shuffle(nodes.begin(), nodes.end());
  return nodes;
}

pvl::graph_adj_list build_tree(int n, int d) {
  std::srand(time(NULL));
  d = std::min(d, n-2);
  pvl::vi nodes = random_permutation(n);
  pvl::graph_adj_list g(n, false);
  for (int i = 1; i < d; ++i)
    g.add_edge(nodes[i-1], nodes[i]);
  for (int i = d; i < n; ++i) {
    int j = rand() % (d-2) + 1;
    g.add_edge(nodes[j], nodes[i]);
  }
  return g;
}

TEST(Tree, TreeDiameter) {
  pvl::graph_adj_list g_odd = build_tree(7, 5);
  pvl::vi odd_diam = find_tree_diameter(g_odd);
  EXPECT_EQ(odd_diam.size() % 2, 1);

  pvl::graph_adj_list g_even = build_tree(7, 4);
  pvl::vi even_diam = find_tree_diameter(g_even);
  EXPECT_EQ(even_diam.size() % 2, 0);
}

TEST(Tree, TreeCenters) {
  pvl::graph_adj_list g_odd = build_tree(7, 5);
  pvl::vi odd_centers = find_tree_centers(g_odd);
  EXPECT_EQ(odd_centers.size(), 1);

  pvl::graph_adj_list g_even = build_tree(7, 4);
  pvl::vi even_centers = find_tree_centers(g_even);
  EXPECT_EQ(even_centers.size(), 2);
}
