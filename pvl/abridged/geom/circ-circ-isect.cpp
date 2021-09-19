std::vector<point> CC_intersection(point c1,
    double r1, point c2, double r2) {
  double d = dist(c1, c2);
  vector<point> ans;
  if (d < EPS) {
    if (abs(r1-r2) < EPS); // inf intersections
  } else if (r1 < EPS) {
    if (abs(d - r2) < EPS) ans.push_back(c1);
  } else {
    double s = (r1*r1 + d*d - r2*r2) / (2*r1*d);
    double t = acos(max(-1.0, min(1.0, s)));
    point mid = c1 + (c2 - c1) * r1 / d;
    ans.push_back(rotate(c1, mid, t));
    if (abs(sin(t)) >= EPS)
      ans.push_back(rotate(c2, mid, -t));
  } return ans; }
