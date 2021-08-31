int n, id[N], low[N], st[N], in[N], TOP, ID;
int scc[N], SCC_SIZE; // 0 <= scc[u] < SCC_SIZE
vector<int> adj[N]; // 0-based adjlist
void dfs(int u) {
  id[u] = low[u] = ID++;
  st[TOP++] = u; in[u] = 1;
  for (int v : adj[u]) {
    if (id[v] == -1) {
      dfs(v);
      low[u] = min(low[u], low[v]);
    } else if (in[v] == 1)
      low[u] = min(low[u], id[v]); }
  if (id[u] == low[u]) {
    int sid = SCC_SIZE++;
    do {
      int v = st[--TOP];
      in[v] = 0; scc[v] = sid;
    } while (st[TOP] != u); }}
void tarjan() { // call tarjan() to load SCC
  memset(id, -1, sizeof(int) * n);
  SCC_SIZE = ID = TOP = 0;
  for (int i = 0; i < n; ++i)
    if (id[i] == -1) dfs(i); }
