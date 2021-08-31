void test() {
  const int n = 10;
  vi ar(n);
  for (int i = 0; i < n; ++i)
    ar[i] = randint(0, 100);

  fenwick fn(ar);
  for (int i = 0; i < n; ++i)
    assert_equal(fn.get(i), ar[i]);
  for (int i = 0; i < n; ++i) {
    int sum = 0;
    for (int j = i; j < n; ++j) {
      sum += ar[j];
      assert_equal(fn.sum(i, j), sum);
    }
  }

  int sum = 0;
  for (int i = 0; i < n; ++i)
    sum += ar[i];

  std::vector<int> some_perm(n);
  for (int i = 0; i < n; ++i)
    some_perm[i] = i;
  std::random_shuffle(some_perm.begin(), some_perm.end());

  for (int i = 0; i < n/2; ++i) {
    int j = some_perm[i];
    sum += i;
    fn.add(j, i);
  }
  assert_equal(fn.sum(0, n-1), sum);
  for (int i = n/2; i < n; ++i) {
    int j = some_perm[i];
    sum += i;
    fn.add(j, i);
  }
  assert_equal(fn.sum(0, n-1), sum);

  // ---------------------------------------------

  vi br(n, 0);
  fn = fenwick(br);

  for (int i = 0; i < n; ++i)
    assert_equal(fn.get(i), br[i]);

  for (int i = 0; i < 100; ++i) {
    int a = randint(0, n-1);
    int b = randint(0, n-1);
    int v = randint(0, 100);
    if (a > b)  std::swap(a, b);

    assert_true(0 <= a and a < n);
    assert_true(0 <= b and b < n);

    fn.add(a, b, v);
    for (int j = a; j <= b; ++j)
      br[j] += v;

    for (int j = 0; j < n; ++j)
      assert_equal(fn.get1(j), br[j]);
  }
}
