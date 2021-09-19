const int N = 100, LGN = 20;
int lg[N], A[N][N], st[LGN][LGN][N][N];
void build(int n, int m) {
  for(int k=2; k<=std::max(n,m); ++k) lg[k] = lg[k>>1]+1;
  for(int i = 0; i < n; ++i)
    for(int j = 0; j < m; ++j)
      st[0][0][i][j] = A[i][j];
  for(int bj = 0; (2 << bj) <= m; ++bj)
    for(int j = 0; j + (2 << bj) <= m; ++j)
      for(int i = 0; i < n; ++i)
        st[0][bj+1][i][j] =
          std::max(st[0][bj][i][j],
                   st[0][bj][i][j + (1 << bj)]);
  for(int bi = 0; (2 << bi) <= n; ++bi)
    for(int i = 0; i + (2 << bi) <= n; ++i)
      for(int j = 0; j < m; ++j)
        st[bi+1][0][i][j] =
          std::max(st[bi][0][i][j],
                   st[bi][0][i + (1 << bi)][j]);
  for(int bi = 0; (2 << bi) <= n; ++bi)
    for(int i = 0; i + (2 << bi) <= n; ++i)
      for(int bj = 0; (2 << bj) <= m; ++bj)
        for(int j = 0; j + (2 << bj) <= m; ++j) {
          int ik = i + (1 << bi);
          int jk = j + (1 << bj);
          st[bi+1][bj+1][i][j] =
            std::max(std::max(st[bi][bj][i][j],
                              st[bi][bj][ik][j]),
                     std::max(st[bi][bj][i][jk],
                              st[bi][bj][ik][jk])); } }
int query(int x1, int x2, int y1, int y2) {
  int kx = lg[x2 - x1 + 1],   ky = lg[y2 - y1 + 1];
  int x12 = x2 - (1<<kx) + 1, y12 = y2 - (1<<ky) + 1;
  return std::max(std::max(st[kx][ky][x1][y1],
                           st[kx][ky][x1][y12]),
                  std::max(st[kx][ky][x12][y1],
                           st[kx][ky][x12][y12])); }
