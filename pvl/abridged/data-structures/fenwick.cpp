struct fenwick {
  vi ar;
  fenwick(vi &_ar) : ar(_ar.size(), 0) {
    for (int i = 0; i < ar.size(); ++i) {
      ar[i] += _ar[i];
      int j = i | (i+1);
      if (j < ar.size())
        ar[j] += ar[i]; } }
  int sum(int i) {
    int res = 0;
    for (; i >= 0; i = (i & (i+1)) - 1)
      res += ar[i];
    return res; }
  int sum(int i, int j) {  return sum(j) - sum(i-1);  }
  void add(int i, int val) {
    for (; i < ar.size(); i |= i+1)
      ar[i] += val; }
  int get(int i) {
    int res = ar[i];
    if (i) {
      int lca = (i & (i+1)) - 1;
      for (--i; i != lca; i = (i&(i+1))-1)
        res -= ar[i]; }
    return res; }
  void set(int i, int val) {  add(i, -get(i) + val);  }
  // range update, point query //
  void add(int i, int j, int val) {
    add(i, val); add(j+1, -val); }
  int get1(int i) { return sum(i); } };
