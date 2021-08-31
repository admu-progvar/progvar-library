struct graph {
  int n;
  std::vector<iii> edges;
  graph(int n) : n(n) {}
  void add_edge(int u, int v, int w) {
    edges.push_back({w, {u, v}});
  }
};
