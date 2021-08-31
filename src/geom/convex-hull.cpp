// counterclockwise hull in p[], returns size of hull
bool xcmp(const point& a, const point& b) {
  return a.x < b.x || (a.x == b.x && a.y < b.y); }
int convex_hull(point p[], int n) {
  std::sort(p, p + n, xcmp); if (n <= 1) return n;
  int k = 0; point *h = new point[2 * n];
  double zer = EPS; // -EPS to include collinears
  for (int i = 0; i < n; h[k++] = p[i++])
    while (k >= 2 && cross(h[k-2],h[k-1],p[i]) < zer)
      --k;
  for(int i = n-2, t = k; i >= 0; h[k++] = p[i--])
    while (k > t && cross(h[k-2],h[k-1],p[i]) < zer)
      --k;
  k -= 1 + (h[0].x==h[1].x&&h[0].y==h[1].y ? 1 : 0);
  copy(h, h + k, p); delete[] h; return k; }
