#ifndef PVL_GRAPHS_CENTROID_DECOMPOSITION_HPP_
#define PVL_GRAPHS_CENTROID_DECOMPOSITION_HPP_ 1

#include <vector>

#include "./base.hpp"
#include "./math/constants.hpp"

namespace pvl {

struct centroid_decomposition_graph {
    int n, logn, *sz, *shortest, *seph;
    int **jump, **path;
    vi *adj;
    centroid_decomposition_graph(
        int n, int logn = 20
    ) : n(n), logn(logn) {
        adj = new vi[n];
        sz = new int[n];
        shortest = new int[n];
        seph = new int[n];
        jump = new int*[n];
        path = new int*[n];
        for (int u = 0; u < n; ++u) {
            sz[u] = -1;
            shortest[u] = INT_INF;
            seph[u] = -1;
            jump[u] = new int[logn];
            path[u] = new int[logn];
        }
    }
    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void separate(int h = 0, int u = 0) {
        dfs(u, -1);
        int sep = u;
        down:
        for (int v : adj[sep])
            if (sz[v] < sz[sep] && sz[v] > sz[u]/2) {
                sep = v;
                goto down;
            }
        seph[sep] = h;
        makepaths(sep, sep, -1, 0);
        for (int v : adj[sep])
            separate(h+1, v);
    }
    int dfs(int u, int p) {
        sz[u] = 1;
        for (int v : adj[u])
            if (v != p)
                sz[u] += dfs(v, u);
        return sz[u];
    }
    void makepaths(int sep, int u, int p, int len) {
        jump[u][seph[sep]] = sep;
        path[u][seph[sep]] = len;

        int parent_idx = -1;
        for (int i = 0; i < adj[u].size(); ++i) {
            if (adj[u][i] == p)
                parent_idx = i;
            else
                makepaths(sep, adj[u][i], u, len + 1);
        }
        if (p == sep) {
            std::swap(
                adj[u][parent_idx],
                adj[u].back()
            );
            adj[u].pop_back();
        }
    }

    void paint(int u) {
        for (int h = 0; h <= seph[u]; ++h)
            shortest[jump[u][h]] = (
                std::min(
                    shortest[jump[u][h]],
                    path[u][h]
                )
            );
    }
    int closest(int u) {
        int ans = INT_INF;
        for (int h = 0; h <= seph[u]; ++h)
            ans = std::min(
                ans, path[u][h] + shortest[jump[u][h]]
            );
        return ans;
    }
};

}  // namespace pvl

#endif  // PVL_GRAPHS_CENTROID_DECOMPOSITION_HPP_
