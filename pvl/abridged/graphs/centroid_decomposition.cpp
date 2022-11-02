#define MAXV 100100
#define LGMAXV 20
int jmp[MAXV][LGMAXV], path[MAXV][LGMAXV], sz[MAXV],
  seph[MAXV], shortest[MAXV];
struct centroid_decomposition {
  int n; vvi adj;
  centroid_decomposition(int _n) : n(_n), adj(n) { }
  void add_edge(int a, int b) {
    adj[a].push_back(b); adj[b].push_back(a); }
  int dfs(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u]) if (v != p) sz[u] += dfs(v, u);
    return sz[u]; }
  void makepaths(int sep, int u, int p, int len) {
    jmp[u][seph[sep]] = sep, path[u][seph[sep]] = len;
    int bad = -1;
    for (int i = 0; i < adj[u].size(); ++i) {
      if (adj[u][i] == p) bad = i;
      else makepaths(sep, adj[u][i], u, len + 1); }
    if (p == sep) // remove bad edge
      swap(adj[u][bad], adj[u].back()), adj[u].pop_back(); }
  void separate(int h=0, int u=0) {
    dfs(u, -1); int sep = u;
    down:
    for (int nxt : adj[sep])
      if (sz[nxt] < sz[sep] && sz[nxt] > sz[u]/2)
        sep = nxt, goto down;
    seph[sep] = h, makepaths(sep, sep, -1, 0);
    for (int i = 0; i < adj[sep].size(); ++i)
      separate(h+1, adj[sep][i]); }
  void paint(int u) {
    for (int h = 0; h < seph[u] + 1; ++h)
      shortest[jmp[u][h]] =
        std::min(shortest[jmp[u][h]], path[u][h]); }
  int closest(int u) {
    int mn = INF/2;
    for (int h = 0; h < seph[u] + 1; ++h)
      mn = std::min(mn, path[u][h] + shortest[jmp[u][h]]);
    return mn; } };
