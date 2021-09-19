void test() {
  const int n = 10;
  vi ar(n);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    ar[i] = randint(0, 100);
    sum += ar[i];
  }

  segtree st(ar);
  for (int i = 0; i < n; ++i)
    assert_equal(ar[i], st.query(i, i, 1, 0, n-1));
  assert_equal(sum, st.query(0, n-1, 1, 0, n-1));

  for (int i = 0; i < 100; ++i) {
    int u = randint(0, n-1);
    int v = randint(0, n-1);
    int w = randint(-100, 100);

    if (u > v)  std::swap(u, v);

    for (int j = u; j <= v; ++j) {
      ar[j] += w;
      st.update(j, j, w, 1, 0, n-1);
    }
    for (int j = u; j <= v; ++j)
      assert_equal(ar[j], st.query(j, j, 1, 0, n-1));

    sum += (v - u + 1) * w;
    assert_equal(sum, st.query(0, n-1, 1, 0, n-1));

    int a = randint(0, u);
    int b = randint(v, n-1);

    int part_sum = 0;
    for (int j = a; j <= b; ++j)
      part_sum += ar[j];

    assert_equal(part_sum, st.query(a, b, 1, 0, n-1));
  }
}
