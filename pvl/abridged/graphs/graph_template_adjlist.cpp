struct graph {
  int n, *dist;
  vii *adj;
  graph(int n) {
    this->n = n;
    adj = new vii[n];
    dist = new int[n];
  }
  void add_edge(int u, int v, int w) {
    adj[u].push_back({v, w});
    // adj[v].push_back({u, w});
  }
};
