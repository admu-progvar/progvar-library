#define MAXV 2000
int q[MAXV], d[MAXV];
struct flow_network {
  struct edge { int v, nxt, cap;
    edge(int _v, int _cap, int _nxt)
      : v(_v), nxt(_nxt), cap(_cap) { } };
  int n, *head, *curh; vector<edge> e, e_store;
  flow_network(int _n) : n(_n) {
    curh = new int[n];
    memset(head = new int[n], -1, n*sizeof(int)); }
  void reset() { e = e_store; }
  void add_edge(int u, int v, int uv, int vu=0) {
    e.push_back(edge(v,uv,head[u])); head[u]=(int)size(e)-1;
    e.push_back(edge(u,vu,head[v])); head[v]=(int)size(e)-1;}
  int augment(int v, int t, int f) {
    if (v == t) return f;
    for (int &i = curh[v], ret; i != -1; i = e[i].nxt)
      if (e[i].cap > 0 && d[e[i].v] + 1 == d[v])
        if ((ret = augment(e[i].v, t, min(f, e[i].cap))) > 0)
          return (e[i].cap -= ret, e[i^1].cap += ret, ret);
    return 0; }
  int max_flow(int s, int t, bool res=true) {
    e_store = e;
    int l, r, f = 0, x;
    while (true) {
      memset(d, -1, n*sizeof(int));
      l = r = 0, d[q[r++] = t] = 0;
      while (l < r)
        for (int v = q[l++], i = head[v]; i != -1; i=e[i].nxt)
          if (e[i^1].cap > 0 && d[e[i].v] == -1)
            d[q[r++] = e[i].v] = d[v]+1;
      if (d[s] == -1) break;
      memcpy(curh, head, n * sizeof(int));
      while ((x = augment(s, t, INF)) != 0) f += x; }
    if (res) reset();
    return f; } };
bool same[MAXV];
pair<vii, vvi> construct_gh_tree(flow_network &g) {
  int n = g.n, v;
  vii par(n, ii(0, 0)); vvi cap(n, vi(n, -1));
  rep(s,1,n) {
    int l = 0, r = 0;
    par[s].second = g.max_flow(s, par[s].first, false);
    memset(d, 0, n * sizeof(int));
    memset(same, 0, n * sizeof(bool));
    d[q[r++] = s] = 1;
    while (l < r) {
      same[v = q[l++]] = true;
      for (int i = g.head[v]; i != -1; i = g.e[i].nxt)
        if (g.e[i].cap > 0 && d[g.e[i].v] == 0)
          d[q[r++] = g.e[i].v] = 1; }
    rep(i,s+1,n)
      if (par[i].first == par[s].first && same[i])
        par[i].first = s;
    g.reset(); }
  rep(i,0,n) {
    int mn = INF, cur = i;
    while (true) {
      cap[cur][i] = mn;
      if (cur == 0) break;
      mn = min(mn, par[cur].second), cur = par[cur].first; } }
  return make_pair(par, cap); }
int compute_max_flow(int s, int t, const pair<vii, vvi> &gh) {
  int cur = INF, at = s;
  while (gh.second[at][t] == -1)
    cur = min(cur, gh.first[at].second),
    at = gh.first[at].first;
  return min(cur, gh.second[at][t]); }
