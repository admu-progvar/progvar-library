// insert inside code for finding bridges
// requires union_find and hasher
graph build_bridge_tree() {
  union_find uf(n);
  for (int u = 0; u < n; ++u) {
    for (int v : adj[u]) {
      ii uv = { std::min(u, v), std::max(u, v) };
      if (bridges.find(uv) == bridges.end())
        uf.unite(u, v); } }
  hasher h;
  for (int u = 0; u < n; ++u)
    if (u == uf.find(u))  h.get_hash(u);
  int tn = h.h.size();
  graph tree(tn);
  for (int i = 0; i < M; ++i) {
    int ui = h.get_hash(uf.find(u));
    int vi = h.get_hash(uf.find(v));
    if (ui != vi) tree.add_edge(ui, vi); }
  return tree; }
