struct fenwick {
  vi ar;
  fenwick(vi &_ar) : ar(_ar.size(), 0) {
    for (int i = 0; i < ar.size(); ++i) {
      ar[i] = std::max(ar[i], _ar[i]);
      int j = i | (i+1);
      if (j < ar.size())
        ar[j] = std::max(ar[j], ar[i]); } }
  void set(int i, int v) {
    for (; i < ar.size(); i |= i+1)
      ar[i] = std::max(ar[i], v); }
  // max[0..i]
  int max(int i) {
    int res = -INF;
    for (; i >= 0; i = (i & (i+1)) - 1)
      res = std::max(res, ar[i]);
    return res; } };
