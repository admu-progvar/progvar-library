#include "graph_template_adjlist.cpp"
// insert inside graph; needs n, vis[], and adj[]
void prim(viii &res, int s=0) {
  viii().swap(res); // or use res.clear();
  std::priority_queue<ii, vii, std::greater<ii> > pq;
  pq.push{{0, s}};
  vis[s] = true;
  while (!pq.empty()) {
    int u = pq.top().second;    pq.pop();
    vis[u] = true;
    for (auto &[v, w] : adj[u]) {
      if (v == u)   continue;
      if (vis[v])   continue;
      res.push_back({w, {u, v}});
      pq.push({w, v}); } } }
