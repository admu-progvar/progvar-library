struct graph {
  int n, **mat;
  graph(int n) {
    this->n = n;
    mat = new int*[n];
    for (int i = 0; i < n; ++i) {
      mat[i] = new int[n];
      for (int j = 0; j < n; ++j)
        mat[i][j] = INF;
      mat[i][i] = 0;
    }
  }
  void add_edge(int u, int v, int w) {
    mat[u][v] = std::min(mat[u][v], w);
    // mat[v][u] = std::min(mat[v][u], w);
  }
};
