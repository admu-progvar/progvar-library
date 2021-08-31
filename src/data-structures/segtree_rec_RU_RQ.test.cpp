void test() {
  const int n = 10;
  vi ar(n);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    ar[i] = randint(0, 100);
    sum += ar[i];
  }

  segtree *root = new segtree(ar, 0, n-1);
  for (int i = 0; i < n; ++i)
    assert_equal(ar[i], root->query(i, i));
  assert_equal(sum, root->query(0, n-1));

  for (int i = 0; i < 100; ++i) {
    int u = randint(0, n-1);
    int v = randint(0, n-1);
    int w = randint(-100, 100);

    if (u > v)  std::swap(u, v);

    for (int j = u; j <= v; ++j) {
      ar[j] += w;
      root->increase(j, j, w);
    }
    for (int j = u; j <= v; ++j)
      assert_equal(ar[j], root->query(j, j));

    sum += (v - u + 1) * w;
    assert_equal(sum, root->query(0, n-1));

    int a = randint(0, u);
    int b = randint(v, n-1);

    int part_sum = 0;
    for (int j = a; j <= b; ++j)
      part_sum += ar[j];

    assert_equal(part_sum, root->query(a, b));
  }
}
