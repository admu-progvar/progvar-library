#define MAXV 1000
#define MAXE 5000
int indeg[MAXV], outdeg[MAXV], res[MAXE + 1];
ii start_end(graph &g) {
  int start = -1, end = -1, any = 0, c = 0;
  for (int u = 0; u < n; ++u) {
    if (outdeg[u] > 0) any = u;
    if (indeg[u] + 1 == outdeg[u]) start = u, c++;
    else if (indeg[u] == outdeg[u] + 1) end = u, c++;
    else if (indeg[u] != outdeg[u]) return {-1, -1}; }
  if ((start == -1) != (end == -1) || (c != 2 && c != 0))
    return {-1,-1};
  if (start == -1) start = end = any;
  return {start, end}; }
bool euler_path(graph &g) {
  ii se = start_end(g);
  int cur = se.first, at = g.edges.size() + 1;
  if (cur == -1) return false;
  std::stack<int> s;
  while (true) {
    if (outdeg[cur] == 0) {
      res[--at] = cur;
      if (s.empty()) break;
      cur = s.top(); s.pop();
    } else s.push(cur), cur = g.adj[cur][--outdeg[cur]]; }
  return at == 0; }
