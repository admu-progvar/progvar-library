bool inPolygon(point q, point p[], int n) {
  bool in = false;
  for (int i = 0, j = n - 1; i < n; j = i++)
    in ^= (((p[i].y > q.y) != (p[j].y > q.y)) &&
      q.x < (p[j].x - p[i].x) * (q.y - p[i].y) /
      (p[j].y - p[i].y) + p[i].x);
  return in; }
bool onPolygon(point q, point p[], int n) {
  for (int i = 0, j = n - 1; i < n; j = i++)
  if (abs(dist(p[i], q) + dist(p[j], q) -
          dist(p[i], p[j])) < EPS)
    return true;
  return false; }
