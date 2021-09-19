void test() {
  const int n = 10;
  vi ar(n);
  for (int i = 0; i < n; ++i)
    ar[i] = randint(0, 100);

  fenwick fn(ar);

  int max_val = -INF;
  for (int i = 0; i < n; ++i) {
    max_val = std::max(max_val, ar[i]);
    assert_equal(fn.max(i), max_val);
  }
}
