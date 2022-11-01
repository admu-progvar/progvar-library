struct Line {
  ll k, d;
  ll eval(ll x) { return k * x + d; } };
struct LiChaoNode {
  Line line;
  int l, r;
  LiChaoNode() : l(0), r(0) {
    line = Line({0, numeric_limits<long long>::max() / 2}); }
  LiChaoNode(Line line) : line(line), l(0), r(0) {}
} t[50 * N];
int T;
int upd(int pre, Line nw, int l, int r) {
  int m = (l + r) / 2;
  int id = ++T;
  t[id].line = t[pre].line;
  bool lef = nw.eval(l) < t[id].line.eval(l);
  bool mid = nw.eval(m) < t[id].line.eval(m);
  if(mid) swap(t[id].line, nw);
  if(l == r) return id;
  if(lef != mid) {
    if(!t[pre].l) t[id].l = ++T, t[T] = LiChaoNode(nw);
    else t[id].l = upd(t[pre].l, nw, l, m);
    t[id].r = t[pre].r;
  } else {
    if(!t[pre].r) t[id].r = ++T, t[T] = LiChaoNode(nw);
    else t[id].r = upd(t[pre].r, nw, m + 1, r);
    t[id].l = t[pre].l; }
  return id; }
ll Query(int cur, int x, int l, int r) {
  ll val = t[cur].line.eval(x);
  int m = (l + r) / 2;
  if(l < r) {
    if(x<=m && t[cur].l) val=min(val, Query(t[cur].l,x,l,m));
    if(x>m && t[cur].r) val=min(val, Query(t[cur].r,x,m+1,r)); }
  return val; }
struct PersistentLiChaoTree {
  int L, R;
  vector<int> roots;
  PersistentLiChaoTree() : L(-1e9), R(1e9) {
    T = 1; roots = {1}; }
  PersistentLiChaoTree(int L, int R) : L(L), R(R) {
    T = 1; roots.push_back(1); }
  void add_line(Line line) {
    int root = upd(roots.back(), line, L, R);
    roots.push_back(root); }
  ll query(int i, int x) { return Query(roots[i], x, L, R); } };
