#include <vector>

#include <gtest/gtest.h>
#include "../pvl/math/constants.hpp"
#include "../pvl/graphs/shortest_paths/dijkstra.hpp"

int N = 5;


pvl::graph_dijkstra<int> build_graph() {
  /*
  +-(2)-->1-(1)-+
  |             |
  |             v  
  0             2<--(4)--4
  |             ^
  |             |
  +-(1)-->3-(3)-+
  */
  pvl::graph_dijkstra<int> g(N, true);
  g.add_edge(0, 1, 2);
  g.add_edge(1, 2, 1);
  g.add_edge(0, 3, 1);
  g.add_edge(3, 2, 3);
  g.add_edge(4, 2, 4);
  return g;
}

TEST(ShortestPaths, DijkstraSingleSourceShortestPath) {
  pvl::graph_dijkstra<int> g = build_graph();

  std::vector<int> dist = g.single_source_shortest_paths(0);
  for (int u = 0; u < N; ++u)
    EXPECT_EQ(dist[u], g.dist[u]);

  EXPECT_EQ(g.dist[0], 0);
  EXPECT_EQ(g.dist[1], 2);
  EXPECT_EQ(g.dist[2], 3);
  EXPECT_EQ(g.dist[3], 1);
  EXPECT_EQ(g.dist[4], pvl::INT_INF);
}

TEST(ShortestPaths, DijkstraAllPairsShortestPath) {
  pvl::graph_dijkstra<int> g = build_graph();

  std::vector<std::vector<int>> mat = {
    {0,            2,            3, 1,            pvl::INT_INF},
    {pvl::INT_INF, 0,            1, pvl::INT_INF, pvl::INT_INF},
    {pvl::INT_INF, pvl::INT_INF, 0, pvl::INT_INF, pvl::INT_INF},
    {pvl::INT_INF, pvl::INT_INF, 3, 0,            pvl::INT_INF},
    {pvl::INT_INF, pvl::INT_INF, 4, pvl::INT_INF, 0},
  };

  std::vector<std::vector<int>> dists = g.all_pairs_shortest_paths();
  for (int u = 0; u < N; ++u)
    for (int v = 0; v < N; ++v)
      EXPECT_EQ(dists[u][v], mat[u][v]);
}
