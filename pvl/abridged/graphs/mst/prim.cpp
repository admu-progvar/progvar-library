#include "graph_template_adjlist.cpp"
// insert inside graph; needs n, vis[], and adj[]
void prim(viii &res, int s=0) {
  res.clear();
  std::priority_queue<iii, viii, std::greater<iii>> pq;
  vis[s] = true;
  for (auto &[v, w] : adj[s])
    if (!vis[v])
      pq.push({w, {s, v}});
  while (!pq.empty()) {
    auto edge = pq.top();    pq.pop();
    int u = edge.second.second;
    if (vis[u]) continue;
    vis[u] = true;
    res.push_back(edge);
    for (auto &[v, w] : adj[u])
      if (!vis[v])
        pq.push({w, {u, v}});
  }
}
