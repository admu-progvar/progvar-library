// USAGE: hull.insert_line(m, b); hull.gety(x);
bool UPPER_HULL = true; // you can edit this
bool IS_QUERY = false, SPECIAL = false;
struct line {
  ll m, b; line(ll m=0, ll b=0): m(m), b(b) {}
  mutable std::multiset<line>::iterator it;
  const line *see(std::multiset<line>::iterator it)const;
  bool operator < (const line& k) const {
    if (!IS_QUERY) return m < k.m;
    if (!SPECIAL) {
      ll x = k.m; const line *s = see(it);
      if (!s) return 0;
      return (b - s->b) < (x) * (s->m - m);
    } else {
      ll y = k.m; const line *s = see(it);
      if (!s) return 0;
      ll n1 = y - b, d1 = m;
      ll n2 = b - s->b, d2 = s->m - m;
      if (d1 < 0) n1 *= -1, d1 *= -1;
      if (d2 < 0) n2 *= -1, d2 *= -1;
      return (n1) * d2 > (n2) * d1; } } };
struct dynamic_hull : std::multiset<line> {
  bool bad(iterator y) {
    iterator z = next(y);
    if (y == begin()) {
      if (z == end()) return 0;
      return y->m == z->m && y->b <= z->b; }
    iterator x = prev(y);
    if (z == end()) return y->m == x->m && y->b <= x->b;
    return (x->b - y->b)*(z->m - y->m)>=
           (y->b - z->b)*(y->m - x->m); }
  iterator next(iterator y) {return ++y;}
  iterator prev(iterator y) {return --y;}
  void insert_line(ll m, ll b) {
    IS_QUERY = false;
    if (!UPPER_HULL) m *= -1;
    iterator y = insert(line(m, b));
    y->it = y; if (bad(y)) {erase(y); return;}
    while (next(y) != end() && bad(next(y)))
      erase(next(y));
    while (y != begin() && bad(prev(y)))
      erase(prev(y)); }
  ll gety(ll x) {
    IS_QUERY = true; SPECIAL = false;
    const line& L = *lower_bound(line(x, 0));
    ll y = (L.m) * x + L.b;
    return UPPER_HULL ? y : -y; }
  ll getx(ll y) {
    IS_QUERY = true; SPECIAL = true;
    const line& l = *lower_bound(line(y, 0));
    return /*floor*/ ((y - l.b + l.m - 1) / l.m); }
} hull;
const line* line::see(std::multiset<line>::iterator it)
const {return ++it == hull.end() ? NULL : &*it;}
