/*
Get intersection points of circle at center $c$, radius $r$,
and line $\overline{ab}$.
*/
std::vector<point> CL_inter(point c, double r,
    point a, point b) {
  point p = projLine(c, a, b);
  double d = abs(c - p); vector<point> ans;
  if (d > r + EPS); // none
  else if (d > r - EPS) ans.push_back(p); // tangent
  else if (d < EPS) { // diameter
    point v = r * (b - a) / abs(b - a);
    ans.push_back(c + v);
    ans.push_back(c - v);
  } else {
    double t = acos(d / r);
    p = c + (p - c) * r / d;
    ans.push_back(rotate(c, p, t));
    ans.push_back(rotate(c, p, -t));
  } return ans; }
