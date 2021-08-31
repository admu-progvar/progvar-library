int n;
std::vector<vi> capacity, flow;
vi height, excess;
void push(int u, int v) {
  int d = min(excess[u], capacity[u][v] - flow[u][v]);
  flow[u][v] += d;    flow[v][u] -= d;
  excess[u] -= d;     excess[v] += d; }
void relabel(int u) {
  int d = INF;
  for (int i = 0; i < n; i++)
    if (capacity[u][i] - flow[u][i] > 0)
      d = min(d, height[i]);
  if (d < INF)  height[u] = d + 1; }
vi find_max_height_vertices(int s, int t) {
  vi max_height;
  for (int i = 0; i < n; i++) {
    if (i != s && i != t && excess[i] > 0) {
      if (!max_height.empty()&&height[i]>height[max_height[0]])
        max_height.clear();
      if (max_height.empty()||height[i]==height[max_height[0]])
        max_height.push_back(i); } }
  return max_height; }
int max_flow(int s, int t) {
  flow.assign(n, vi(n, 0));
  height.assign(n, 0);    height[s] = n;
  excess.assign(n, 0);    excess[s] = INF;
  for (int i = 0; i < n; i++) if (i != s) push(s, i);
  vi current;
  while (!(current = find_max_height_vertices(s, t)).empty()) {
    for (int i : current) {
      bool pushed = false;
      for (int j = 0; j < n && excess[i]; j++) {
        if (capacity[i][j] - flow[i][j] > 0 &&
            height[i] == height[j] + 1) {
          push(i, j);
          pushed = true; } }
      if (!pushed) relabel(i), break; } }
  int max_flow = 0;
  for (int i = 0; i < n; i++) max_flow += flow[i][t];
  return max_flow; }
