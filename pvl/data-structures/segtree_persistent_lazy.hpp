#ifndef PVL_DATA_STRUCTURES_SEGTREE_PERSISTENT_LAZY_HPP_
#define PVL_DATA_STRUCTURES_SEGTREE_PERSISTENT_LAZY_HPP_ 1

namespace pvl {

struct segtree {
  int i, j, val, delta;
  segtree *l, *r;

  segtree(int i, int j)
    : segtree(i, j, 0, 0, nullptr, nullptr) {}
  segtree(int i, int j, int v, int d, segtree *l, segtree *r)
    : i(i), j(j), val(v), delta(d), l(l), r(r) {}

  segtree *apply_delta(int d) {
    return new segtree(i, j, val, delta + d, l, r);
  }

  segtree *push() {
    int k = (i + j) / 2;
    if (!l) {
      l = new segtree(i, k);
    }
    if (!r) {
      r = new segtree(k + 1, j);
    }
    if (delta != 0) {
      val += (j - i + 1) * delta;
      if (i != j) {
        l = l->apply_delta(delta);
        r = r->apply_delta(delta);
      }
      delta = 0;
    }
    return this;
  }

  segtree *update(int _i, int _j, int _val) {
    push();
    if (_i <= i && j <= _j) {
      return apply_delta(_val)->push();
    } else if (_j < i || j < _i) {
      return this;
    } else {
      segtree *_l = l->update(_i, _j, _val);
      segtree *_r = r->update(_i, _j, _val);
      return new segtree(i, j, _l->val + _r->val, 0, _l, _r);
    }
  }

  int query(int _i, int _j) {
    push();
    if (_i <= i && j <= _j) {
      return val;
    } else if (_j < i || j < _i) {
      return 0;
    } else {
      return l->query(_i, _j) + r->query(_i, _j);
    }
  }
};

}  // namespace pvl

#endif  // PVL_DATA_STRUCTURES_SEGTREE_PERSISTENT_LAZY_HPP_
