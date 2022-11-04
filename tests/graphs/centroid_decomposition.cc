#include <gtest/gtest.h>
#include "../pvl/graphs/centroid_decomposition.hpp"


TEST(CentroidDecomposition, ClosestPainted) {
    int N = 7;
    pvl::centroid_decomposition_graph g(N);
    for (int u = 1; u < N; ++u)
        g.add_edge(u-1, u);

    g.separate();

    pvl::vi expected_seph = {2, 1, 2, 0, 2, 1, 2};
    for (int u = 0; u < N; ++u)
        EXPECT_EQ(g.seph[u], expected_seph[u]);

    pvl::vi expected_closest = {
        pvl::INT_INF, pvl::INT_INF, pvl::INT_INF, pvl::INT_INF,
        pvl::INT_INF, pvl::INT_INF, pvl::INT_INF
    };
    for (int u = 0; u < N; ++u)
        EXPECT_EQ(g.closest(u), expected_closest[u]);

    g.paint(4);
    expected_closest = {4, 3, 2, 1, 0, 1, 2};
    for (int u = 0; u < N; ++u)
        EXPECT_EQ(g.closest(u), expected_closest[u]);

    g.paint(1);
    expected_closest = {1, 0, 1, 1, 0, 1, 2};
    for (int u = 0; u < N; ++u)
        EXPECT_EQ(g.closest(u), expected_closest[u]);
}
