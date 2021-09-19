#include <gtest/gtest.h>
#include "../pvl/graph/shortest_paths/dijkstra.hpp"

TEST(ShortestPath, Dijkstra) {
  int N = 5;
  pvl::graph_dijkstra<int> g(N, true);
  /*
  +-(2)-->1-(1)-+
  |             |
  |             v
  0             2        4
  |             ^
  |             |
  +-(1)-->3-(3)-+
  */
  g.add_edge(0, 1, 2);
  g.add_edge(1, 2, 1);
  g.add_edge(0, 3, 1);
  g.add_edge(3, 2, 3);

  int INF = 1000;
  g.dijkstra(0, INF);

  EXPECT_EQ(g.dist[0], 0);
  EXPECT_EQ(g.dist[1], 2);
  EXPECT_EQ(g.dist[2], 3);
  EXPECT_EQ(g.dist[3], 1);
  EXPECT_EQ(g.dist[4], INF);
}