struct segtree {
  int i, j, val;
  segtree *l, *r;
  segtree(vi &ar, int _i, int _j) : i(_i), j(_j) {
    if (i == j) {
      val = ar[i];
      l = r = NULL;
    } else {
      int k = (i+j) >> 1;
      l = new segtree(ar, i, k);
      r = new segtree(ar, k+1, j);
      val = l->val + r->val; } }
  void update(int _i, int _val) {
    if (_i <= i and j <= _i) {
      val += _val;
    } else if (_i < i or j < _i) {
      // do nothing
    } else {
      l->update(_i, _val);
      r->update(_i, _val);
      val = l->val + r->val; } }
  int query(int _i, int _j) {
    if (_i <= i and j <= _j) {
      return val;
    } else if (_j < i or j < _i) {
      return 0;
    } else {
      return l->query(_i, _j) + r->query(_i, _j); } } };
