#define cpoint const point&
bool cmpx(cpoint a, cpoint b) {return a.x < b.x;}
bool cmpy(cpoint a, cpoint b) {return a.y < b.y;}
struct KDTree {
  KDTree(point p[],int n): p(p), n(n) {build(0,n);}
  priority_queue< pair<double, point*> > pq;
  point *p; int n, k; double qx, qy, prune;
  void build(int L, int R, bool dvx=false) {
    if (L >= R) return;
    int M = (L + R) / 2;
    nth_element(p + L, p + M, p + R, dvx?cmpx:cmpy);
    build(L, M, !dvx); build(M + 1, R, !dvx); }
  void dfs(int L, int R, bool dvx) {
    if (L >= R) return;
    int M = (L + R) / 2;
    double dx = qx - p[M].x, dy = qy - p[M].y;
    double delta = dvx ? dx : dy;
    double D = dx * dx + dy * dy;
    if (D<=prune && (pq.size()<k||D<pq.top().first)) {
      pq.push(make_pair(D, &p[M]));
      if (pq.size() > k) pq.pop(); }
    int nL = L, nR = M, fL = M + 1, fR = R;
    if (delta > 0) {swap(nL, fL); swap(nR, fR);}
    dfs(nL, nR, !dvx);
    D = delta * delta;
    if (D<=prune && (pq.size()<k||D<pq.top().first))
    dfs(fL, fR, !dvx); }
  // returns k nearest neighbors of (x, y) in tree
  // usage: vector<point> ans = tree.knn(x, y, 2);
  vector<point> knn(double x, double y,
                    int k=1, double r=-1) {
    qx=x; qy=y; this->k=k; prune=r<0?HUGE_VAL:r*r;
    dfs(0, n, false); vector<point> v;
    while (!pq.empty()) {
      v.push_back(*pq.top().second);
      pq.pop();
    } reverse(v.begin(), v.end());
    return v; } };
