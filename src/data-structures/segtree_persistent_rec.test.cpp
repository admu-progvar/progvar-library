void test() {
  const int NUM_ROOTS = 10;
  const int N = 10;

  vi ar(N);
  int sum = 0;

  for (int i = 0; i < N; ++i) {
    ar[i] = randint(0, 100);
    sum += ar[i];
  }

  segtree *roots[NUM_ROOTS];
  roots[0] = new segtree(ar, 0, N-1);

  for (int r = 0; r < NUM_ROOTS; ++r) {
    if (r) {
      int i = randint(0, N-1);
      int v = randint(0, 100);

      ar[i] += v;
      sum += v;
    }

    assert_equal(sum, st.query(0, N-1));
    for (int i = 0; i < N; ++i)
      assert_equal(ar[i], st.query(i, i));
  }
}
