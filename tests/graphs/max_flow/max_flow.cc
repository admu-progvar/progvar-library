#include <vector>

#include <gtest/gtest.h>
#include "../pvl/graphs/max_flow/dinic.hpp"
#include "../pvl/graphs/max_flow/gomory_hu.hpp"

enum nodes {
  A, B, C, D, E, F
};

int N = 6;

pvl::flow_network_dinic build_graph() {
  pvl::flow_network_dinic g(N);
  g.add_edge(A, B, 10, true);
  g.add_edge(A, F, 8, true);

  g.add_edge(B, F, 3, true);
  g.add_edge(F, E, 3, true);
  g.add_edge(E, C, 4, true);
  g.add_edge(B, C, 4, true);

  g.add_edge(B, E, 2, true);
  g.add_edge(F, C, 2, true);

  g.add_edge(F, D, 2, true);
  g.add_edge(C, D, 5, true);
  g.add_edge(E, D, 7, true);

  return g;
}

TEST(FlowAlgorithms, Dinic) {
  pvl::flow_network_dinic g = build_graph();

  EXPECT_EQ(g.calc_max_flow(A, B), 18);
  g.reset();
  EXPECT_EQ(g.calc_max_flow(B, F), 17);
  g.reset();
  EXPECT_EQ(g.calc_max_flow(F, E), 13);
  g.reset();
  EXPECT_EQ(g.calc_max_flow(E, C), 15);
  g.reset();
  EXPECT_EQ(g.calc_max_flow(E, D), 14);
}

TEST(FlowAlgorithms, GomoryHu) {
  pvl::flow_network_dinic g = build_graph();
  pvl::gomory_hu_tree gh(g);

  EXPECT_EQ(gh.calc_max_flow(A, B), 18);
  EXPECT_EQ(gh.calc_max_flow(B, F), 17);
  EXPECT_EQ(gh.calc_max_flow(F, E), 13);
  EXPECT_EQ(gh.calc_max_flow(E, C), 15);
  EXPECT_EQ(gh.calc_max_flow(E, D), 14);
}
