#include <set>
#include <map>
#include <utility>
#include <iostream>
#include <vector>

#include <gtest/gtest.h>

#include "../pvl/graphs/mst/prim.hpp"

enum nodes {
  A, B, C, D, E, F, G,
  H, I, J, K, L, M, N,
  O, P, Q, R, S, T, U,
  V, W, X, Y, Z
};

pvl::graph_adj_list_weighted<int> build_graph() {
  pvl::graph_adj_list_weighted<int> g(8);
  g.add_edge(A, B, 1);
  g.add_edge(A, C, 1);
  g.add_edge(A, D, 1);
  g.add_edge(A, E, 1);
  g.add_edge(A, F, 1);
  g.add_edge(A, G, 1);
  g.add_edge(A, H, 1);
  return g;
}

pvl::graph_edge_list_weighted<int> get_expected_1() {
  pvl::graph_edge_list_weighted<int> g(8);
  g.add_edge(A, B, 1);
  g.add_edge(A, C, 1);
  g.add_edge(A, D, 1);
  g.add_edge(A, E, 1);
  g.add_edge(A, F, 1);
  g.add_edge(A, G, 1);
  g.add_edge(A, H, 1);
  return g;
}

pvl::graph_adj_list_weighted<int> build_graph_2() {
  pvl::graph_adj_list_weighted<int> g(10);
  g.add_edge(A, B, 1);
  g.add_edge(B, C, 2);
  g.add_edge(C, D, 3);
  g.add_edge(D, E, 4);
  g.add_edge(E, J, 5);
  g.add_edge(J, G, 6);
  g.add_edge(G, I, 7);
  g.add_edge(I, F, 8);
  g.add_edge(F, H, 9);
  g.add_edge(A, F, 10);
  g.add_edge(A, E, 11);
  g.add_edge(B, G, 12);
  g.add_edge(C, H, 13);
  g.add_edge(D, I, 14);
  g.add_edge(J, H, 15);
  return g;
}

pvl::graph_edge_list_weighted<int> get_expected_2() {
  pvl::graph_edge_list_weighted<int> g(9);
  g.add_edge(A, B, 1);
  g.add_edge(B, C, 2);
  g.add_edge(C, D, 3);
  g.add_edge(D, E, 4);
  g.add_edge(E, J, 5);
  g.add_edge(J, G, 6);
  g.add_edge(G, I, 7);
  g.add_edge(I, F, 8);
  g.add_edge(F, H, 9);
  return g;
}

TEST(MinimumSpanningTrees, Prim) {
  pvl::graph_adj_list_weighted<int> g = build_graph();
  pvl::graph_edge_list_weighted<int> mst = prim(g, A);
  pvl::graph_edge_list_weighted<int> expect = get_expected_1();
  EXPECT_EQ(expect.edges, mst.edges);
  EXPECT_EQ(expect.weight, mst.weight);

  g = build_graph_2();
  mst = prim(g, A);
  expect = get_expected_2();
  EXPECT_EQ(expect.edges, mst.edges);
  EXPECT_EQ(expect.weight, mst.weight);
}
