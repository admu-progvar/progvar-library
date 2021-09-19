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
      val = l->val + r->val;
  } }
  segtree(int i, int j, segtree *l, segtree *r, int val) :
    i(i), j(j), l(l), r(r), val(val) {}
  segtree* update(int _i, int _val) {
    if (_i <= i and j <= _i)
      return new segtree(i, j, l, r, val + _val);
    else if (_i < i or j < _i)
      return this;
    else {
      segtree *nl = l->update(_i, _val);
      segtree *nr = r->update(_i, _val);
      return new segtree(i, j, nl, nr, nl->val + nr->val); } }
  int query(int _i, int _j) {
    if (_i <= i and j <= _j)
      return val;
    else if (_j < i or j < _i)
      return 0;
    else
      return l->query(_i, _j) + r->query(_i, _j); } };
