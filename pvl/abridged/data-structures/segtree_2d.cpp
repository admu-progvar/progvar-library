struct segtree_2d {
  int n, m, **ar;
  segtree_2d(int n, int m) {
    this->n = n;    this->m = m;
    ar = new int[n];
    for (int i = 0; i < n; ++i) {
      ar[i] = new int[m];
      for (int j = 0; j < m; ++j)
        ar[i][j] = 0; } }
  void update(int x, int y, int v) {
    ar[x + n][y + m] = v;
    for (int i = x + n; i > 0; i >>= 1) {
      for (int j = y + m; j > 0; j >>= 1) {
        ar[i>>1][j] = min(ar[i][j], ar[i^1][j]);
        ar[i][j>>1] = min(ar[i][j], ar[i][j^1]);
  }}} // just call update one by one to build
  int query(int x1, int x2, int y1, int y2) {
    int s = INF;
    if(~x2) for(int a=x1+n, b=x2+n+1; a<b; a>>=1, b>>=1) {
      if (a & 1) s = min(s, query(a++, -1, y1, y2));
      if (b & 1) s = min(s, query(--b, -1, y1, y2));
    } else for (int a=y1+m, b=y2+m+1; a<b; a>>=1, b>>=1) {
      if (a & 1) s = min(s, ar[x1][a++]);
      if (b & 1) s = min(s, ar[x1][--b]);
    } return s; } };
