#include "data-structures/union_find.cpp"
struct tarjan_olca {
  vi ancestor, answers;
  vvi adj;
  vvii queries;
  std::vector<bool> colored;
  union_find uf;
  tarjan_olca(int n, vvi &adj) : adj(adj), uf(n) {
    vi(n).swap(ancestor);
    vvii(n).swap(queries);
    std::vector<bool>(n, false).swap(colored); }
  void query(int x, int y) {
    queries[x].push_back(ii(y, size(answers)));
    queries[y].push_back(ii(x, size(answers)));
    answers.push_back(-1); }
  void process(int u) {
    ancestor[u] = u;
    for (int v : adj[u]) {
      process(v);
      uf.unite(u,v);
      ancestor[uf.find(u)] = u; }
    colored[u] = true;
    for (auto &[a, b]: queries[u])
      if (colored[a]) answers[b] = ancestor[uf.find(a)];
} };
