#include "graph_template_adjlist.cpp"
// insert inside graph; needs n, dist[], and adj[]
void bellman_ford(int s) {
  for (int u = 0; u < n; ++u)
    dist[u] = INF;
  dist[s] = 0;
  for (int i = 0; i < n-1; ++i)
    for (int u = 0; u < n; ++u)
      for (auto &e : adj[u])
        if (dist[u] + e.second < dist[e.first])
          dist[e.first] = dist[u] + e.second; }
// you can call this after running bellman_ford()
bool has_neg_cycle() {
  for (int u = 0; u < n; ++u)
    for (auto &e : adj[u])
      if (dist[e.first] > dist[u] + e.second)
        return true;
  return false; }
