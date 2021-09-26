#include "hopcroft_karp.cpp"
std::vector<bool> alt;
void dfs(bipartite_graph &g, int u) {
  alt[u] = true;
  for (int v: g.adj[u]) {
    alt[v + g.n] = true;
    if (g.R[v] != -1 && !alt[g.R[v]])
      dfs(g, g.R[v]); } }
vi mvc_bipartite(bipartite_graph &g) {
  vi res; g.maximum_matching();
  alt.assign(g.n + g.m, false);
  for (int i = 0; i<g.n; ++i) if (g.L[i] == -1) dfs(g, i);
  for (int i = 0; i<g.n; ++i) if (!alt[i]) res.push_back(i);
  for (int i = 0; i<g.m; ++i)
    if (alt[g.n + i]) res.push_back(g.n + i);
  return res; }
