vector<point> cut(point p[],int n,point a,point b) {
  vector<point> poly;
  for (int i = 0, j = n - 1; i < n; j = i++) {
    double c1 = cross(a, b, p[j]);
    double c2 = cross(a, b, p[i]);
    if (c1 > -EPS) poly.push_back(p[j]);
    if (c1 * c2 < -EPS)
      poly.push_back(line_inter(p[j], p[i], a, b));
  } return poly; }
