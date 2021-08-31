int n, m; // size of A, size of B
int cost[N+1][N+1]; // input cost matrix, 1-indexed
int way[N+1], p[N+1]; // p[i]=j: Ai is matched to Bj
int minv[N+1], A[N+1], B[N+1]; bool used[N+1];
int hungarian() {
  for (int i = 0; i <= N; ++i)
    A[i] = B[i] = p[i] = way[i] = 0; // init
  for (int i = 1; i <= n; ++i) {
    p[0] = i; int R = 0;
    for (int j = 0; j <= m; ++j)
      minv[j] = INF, used[j] = false;
    do {
      int L = p[R], dR = 0;
      int delta = INF;
      used[R] = true;
      for (int j = 1; j <= m; ++j)
        if (!used[j]) {
          int c = cost[L][j] - A[L] - B[j];
          if (c < minv[j])      minv[j] = c, way[j] = R;
          if (minv[j] < delta)  delta = minv[j], dR = j;
        }
      for (int j = 0; j <= m; ++j)
          if (used[j])  A[p[j]] += delta, B[j] -= delta;
          else          minv[j] -= delta;
      R = dR;
    } while (p[R] != 0);
    for (; R != 0; R = way[R])
      p[R] = p[way[R]]; }
  return -B[0]; }
