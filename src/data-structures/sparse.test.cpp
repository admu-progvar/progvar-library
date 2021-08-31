void test() {
  const int n = 10;
  std::vector<int> ar(n);
  for (int i = 0; i < n; ++i)
    ar[i] = randint(0, 100);

  build(ar, n);

  for (int i = 0; i < n; ++i) {
    int min_val = INF;
    for (int j = i; j < n; ++j) {
      min_val = std::min(min_val, ar[j]);
      assert_equal(query(i, j), min_val);
    }
  }
}
