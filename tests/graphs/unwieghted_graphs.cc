#include <gtest/gtest.h>
#include "../pvl/graphs/unweighted_graphs.hpp"


TEST(UnweightedGraphs, AdjacencyListUndirected) {
  int N = 4;
  pvl::graph_adj_list g(N);
  g.add_edge(0, 1);
  g.add_edge(1, 2);
  g.add_edge(2, 3);

  EXPECT_EQ(g.adj[0].size(), 1);
  EXPECT_EQ(g.adj[1].size(), 2);
  EXPECT_EQ(g.adj[2].size(), 2);
  EXPECT_EQ(g.adj[3].size(), 1);
}

TEST(UnweightedGraphs, AdjacencyListDirected) {
  int N = 4;
  pvl::graph_adj_list g(N, true);
  g.add_edge(0, 1);
  g.add_edge(1, 2);
  g.add_edge(2, 3);

  EXPECT_EQ(g.adj[0].size(), 1);
  EXPECT_EQ(g.adj[1].size(), 1);
  EXPECT_EQ(g.adj[2].size(), 1);
  EXPECT_EQ(g.adj[3].size(), 0);
}

TEST(UnweightedGraphs, AdjacencyMatrixUndirected) {
  int N = 4;
  pvl::graph_adj_mat g(N);
  g.add_edge(0, 1);
  g.add_edge(1, 2);
  g.add_edge(2, 1);
  g.add_edge(2, 3);

  EXPECT_EQ(g.mat[0][1], 1);
  EXPECT_EQ(g.mat[1][0], 1);
  EXPECT_EQ(g.mat[1][2], 2);
  EXPECT_EQ(g.mat[2][1], 2);
  EXPECT_EQ(g.mat[2][3], 1);
  EXPECT_EQ(g.mat[3][2], 1);
}

TEST(UnweightedGraphs, AdjacencyMatrixDirected) {
  int N = 4;
  pvl::graph_adj_mat g(N, true);
  g.add_edge(0, 1);
  g.add_edge(1, 2);
  g.add_edge(2, 1);
  g.add_edge(2, 3);

  EXPECT_EQ(g.mat[0][1], 1);
  EXPECT_EQ(g.mat[1][0], 0);
  EXPECT_EQ(g.mat[1][2], 1);
  EXPECT_EQ(g.mat[2][1], 1);
  EXPECT_EQ(g.mat[2][3], 1);
  EXPECT_EQ(g.mat[3][2], 0);
}

TEST(UnweightedGraphs, EdgeListUndirected) {
  int N = 4;
  pvl::graph_edge_list g(N);
  g.add_edge(0, 1);
  g.add_edge(1, 2);
  g.add_edge(2, 1);
  g.add_edge(2, 3);

  EXPECT_EQ(g.edges.size(), 3);
  for (auto &[u, v] : g.edges)
    EXPECT_LT(u, v);
}

TEST(UnweightedGraphs, EdgeListDirected) {
  int N = 4;
  pvl::graph_edge_list g(N, true);
  g.add_edge(0, 1);
  g.add_edge(1, 2);
  g.add_edge(2, 1);
  g.add_edge(2, 3);

  EXPECT_EQ(g.edges.size(), 4);
  EXPECT_TRUE(g.edges.find({0, 1}) != g.edges.end());
  EXPECT_TRUE(g.edges.find({1, 0}) == g.edges.end());
  EXPECT_TRUE(g.edges.find({1, 2}) != g.edges.end());
  EXPECT_TRUE(g.edges.find({2, 1}) != g.edges.end());
  EXPECT_TRUE(g.edges.find({2, 3}) != g.edges.end());
  EXPECT_TRUE(g.edges.find({3, 2}) == g.edges.end());
}
