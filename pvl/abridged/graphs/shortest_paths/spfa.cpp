#include "graph_template_adjlist.cpp"
// insert inside graph;
// needs n, dist[], in_queue[], num_vis[], and adj[]
bool spfa(int s) {
  for (int u = 0; u < n; ++u) {
    dist[u] = INF;
    in_queue[u] = 0;
    num_vis[u] = 0; }
  dist[s] = 0;
  in_queue[s] = 1;
  bool has_negative_cycle = false;
  std::queue<int> q;  q.push(s);
  while (not q.empty()) {
    int u = q.front();  q.pop();  in_queue[u] = 0;
    if (++num_vis[u] >= n)
      dist[u] = -INF, has_negative_cycle = true;
    for (auto &[v, c] : adj[u])
      if (dist[v] > dist[u] + c) {
        dist[v] = dist[u] + c;
        if (!in_queue[v]) {
          q.push(v);
          in_queue[v] = 1; } } }
  return has_negative_cycle; }
