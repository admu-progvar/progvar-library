#include <vector>

#include <gtest/gtest.h>
#include "../pvl/math/constants.hpp"
#include "../pvl/graph/shortest_paths/floyd_warshall.hpp"

int N = 5;


pvl::graph_floyd_marshall<int> build_graph() {
  /*
  +-(2)-->1-(1)-+
  |             |
  |             v  
  0             2<--(4)--4
  |             ^
  |             |
  +-(1)-->3-(3)-+
  */
  pvl::graph_floyd_marshall<int> g(N, true);
  g.add_edge(0, 1, 2);
  g.add_edge(1, 2, 1);
  g.add_edge(0, 3, 1);
  g.add_edge(3, 2, 3);
  g.add_edge(4, 2, 4);
  return g;
}

TEST(ShortestPaths, FloydWarshallAllPairsShortestPath) {
  pvl::graph_floyd_marshall<int> g = build_graph();

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
