void test() {
  const int n = 10;
  std::vector<int> ar(n);
  for (int i = 0; i < n; ++i)
    ar[i] = randint(0, 100);

  cartree treap;
  for (int i = 0; i < n; ++i)
    treap.insert(i, ar[i]);
  for (int i = 0; i < n; ++i)
    assert_equal(treap.get(i), ar[i]);
  for (int i = 0; i < n; ++i) {
    int sum = 0;
    for (int j = i; j < n; ++j) {
      sum += ar[j];
      assert_equal(treap.query(i, j), sum);
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
    treap.update(j, j, i);
  }
  assert_equal(treap.query(0, n-1), sum);
  for (int i = n/2; i < n; ++i) {
    int j = some_perm[i];
    sum += i;
    treap.update(j, j, i);
  }
  assert_equal(treap.query(0, n-1), sum);
}
