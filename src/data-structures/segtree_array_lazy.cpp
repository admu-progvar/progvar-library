struct segtree {
  int n, *vals, *deltas;
  segtree(vi &ar) {
    n = ar.size();
    vals = new int[4*n];
    deltas = new int[4*n];
    build(ar, 1, 0, n-1); }
  void build(vi &ar, int p, int i, int j) {
    deltas[p] = 0;
    if (i == j)
      vals[p] = ar[i];
    else {
      int k = (i + j) / 2;
      build(ar, p<<1, i, k);
      build(ar, p<<1|1, k+1, j);
      pull(p); } }
  void pull(int p) { vals[p] = vals[p<<1] + vals[p<<1|1]; }
  void push(int p, int i, int j) {
    if (deltas[p]) {
      vals[p] += (j - i + 1) * deltas[p];
      if (i != j) {
        deltas[p<<1] += deltas[p];
        deltas[p<<1|1] += deltas[p]; }
      deltas[p] = 0; } }
  void update(int _i, int _j, int v, int p, int i, int j) {
    push(p, i, j);
    if (_i <= i && j <= _j) {
      deltas[p] += v;
      push(p, i, j);
    } else if (_j < i || j < _i) {
      // do nothing
    } else {
      int k = (i + j) / 2;
      update(_i, _j, v, p<<1, i, k);
      update(_i, _j, v, p<<1|1, k+1, j);
      pull(p); } }
  int query(int _i, int _j, int p, int i, int j) {
    push(p, i, j);
    if (_i <= i and j <= _j)
      return vals[p];
    else if (_j < i || j < _i)
      return 0;
    else {
      int k = (i + j) / 2;
      return query(_i, _j, p<<1, i, k) +
             query(_i, _j, p<<1|1, k+1, j); } } };
