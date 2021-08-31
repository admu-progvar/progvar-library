int lg[MAXN+1], spt[20][MAXN];
void build(vi &arr, int n) {
  lg[0] = lg[1] = 0;
  for (int i = 2; i <= n; ++i) lg[i] = lg[i>>1] + 1;
  for (int i = 0; i < n; ++i) spt[0][i] = arr[i];
  for (int j = 0; (2 << j) <= n; ++j)
    for (int i = 0; i + (2 << j) <= n; ++i)
      spt[j+1][i] = std::min(spt[j][i], spt[j][i+(1<<j)]); }
int query(int a, int b) {
  int k = lg[b-a+1], ab = b - (1<<k) + 1;
  return std::min(spt[k][a], spt[k][ab]); }
