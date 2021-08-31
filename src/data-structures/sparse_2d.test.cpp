void test() {
  const int n = 10, m = 20;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      A[i][j] = randint(0, 100);

  build(n, m);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (int ni = i; ni < n; ++ni) {
        for (int nj = j; nj < m; ++nj) {
          int max_val = -INF;
          for (int ki = i; ki <= ni; ++ki)
            for (int kj = j; kj <= nj; ++kj)
              max_val = std::max(max_val, A[ki][kj]);
          assert_equal(query(i, ni, j, nj), max_val);
        }
      }
    }
  }
}
