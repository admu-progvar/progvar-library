void test() {
  const int n = 10;
  vi ar(n);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    ar[i] = randint(0, 100);
    sum += ar[i];
  }

  segtree *root = new segtree(ar, 0, n-1);

  assert_equal(sum, root->query(0, n-1));

  for (int i = 0; i < 100; ++i) {
    int u = randint(0, n-1);
    int v = randint(-100, 100);

    ar[u] += v;
    sum += v;
    root->update(u, v);

    assert_equal(sum, root->query(0, n-1));

    int a = randint(0, u);
    int b = randint(u, n-1);

    int part_sum = 0;
    for (int j = a; j <= b; ++j)
      part_sum += ar[j];

    assert_equal(part_sum, root->query(a, b));
  }
}
