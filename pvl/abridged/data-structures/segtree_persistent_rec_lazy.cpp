struct segtree {
  int i, j, v, delta;
  segtree *l, *r;
  segtree(int i, int j) : segtree(i, j, 0, 0, NULL, NULL) {}
  segtree(int i, int j, int v, int d, segtree *l, segtree *r)
    : i(i), j(j), v(v), delta(d), l(l), r(r) {}
  segtree *apply_delta(int d) {
    return new segtree(i, j, v, delta+d, l, r); }
  segtree *push() {
    int k = (i+j)/2;
    if (!l) l = new segtree(i, k);
    if (!r) r = new segtree(k+1, j);
    if (delta != 0) {
      v += (j-i+1) * delta;
      if (i != j) {
        l = l->apply_delta(delta);
        r = r->apply_delta(delta); }
      delta = 0; }
    return this; }
  segtree *update(int _i, int _j, int _v) {
    push();
    if (_i <= i && j <= _j) return apply_delta(_v)->push();
    else if (_j < i || j < _i) return this;
    else {
      segtree *_l = l->update(_i, _j, _v);
      segtree *_r = r->update(_i, _j, _v);
      return new segtree(i, j, _l->v + _r->v, 0, _l, _r); } }
  int query(int _i, int _j) {
    push();
    if (_i <= i && j <= _j) return v;
    else if (_j < i || j < _i) return 0;
    else return l->query(_i, _j) + r->query(_i, _j); } };
