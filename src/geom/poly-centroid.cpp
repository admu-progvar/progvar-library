point centroid(point p[], int n) {
  point ans(0, 0);
  double z = 0;
  for (int i = 0, j = n - 1; i < n; j = i++) {
    double cp = cross(p[j], p[i]);
    ans += (p[j] + p[i]) * cp;
    z += cp;
  } return ans / (3 * z); }
