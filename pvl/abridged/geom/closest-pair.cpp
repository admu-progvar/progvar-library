bool cmpy(const point& a, const point& b) { return a.y < b.y; }
double closest_pair_sweep(point p[], int n) {
  if (n <= 1) return HUGE_VAL;
  std::sort(p, p + n, cmpy);
  std::set<point> box; box.insert(p[0]);
  double best = 1e13; // infinity, but not HUGE_VAL
  for (int L = 0, i = 1; i < n; ++i) {
    while(L < i && p[i].y - p[L].y > best)
      box.erase(p[L++]);
    point bound(p[i].x - best, p[i].y - best);
    std::set<point>::iterator it = box.lower_bound(bound);
    while (it != box.end() && p[i].x+best >= it->x){
      double dx = p[i].x - it->x;
      double dy = p[i].y - it->y;
      best = std::min(best, std::sqrt(dx*dx + dy*dy));
      ++it; }
    box.insert(p[i]);
  } return best; }
