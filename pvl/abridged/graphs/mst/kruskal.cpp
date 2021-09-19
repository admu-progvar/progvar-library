#include "graph_template_edgelist.cpp"
#include "union_find.cpp"
// insert inside graph; needs n, and edges
void kruskal(viii &res) {
  viii().swap(res); // or use res.clear();
  std::priority_queue<iii, viii, std::greater<iii> > pq;
  for (auto &edge : edges)
    pq.push(edge);
  union_find uf(n);
  while (!pq.empty()) {
    auto node = pq.top();   pq.pop();
    int u = node.second.first;
    int v = node.second.second;
    if (uf.unite(u, v))
      res.push_back(node); } }
