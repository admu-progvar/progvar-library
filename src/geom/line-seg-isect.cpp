/*
Get intersection points of 2D lines/segments $\overline{ab}$
and $\overline{cd}$.
*/
point null(HUGE_VAL, HUGE_VAL);
point line_inter(point a, point b, point c,
                 point d, bool seg = false) {
  point ab(b.x - a.x, b.y - a.y);
  point cd(d.x - c.x, d.y - c.y);
  point ac(c.x - a.x, c.y - a.y);
  double D = -cross(ab, cd); // determinant
  double Ds = cross(cd, ac);
  double Dt = cross(ab, ac);
  if (abs(D) < EPS) { // parallel
    if (seg && abs(Ds) < EPS) { // collinear
      point p[] = {a, b, c, d};
      sort(p, p + 4, [](point a, point b) {
        return a.x < b.x-EPS ||
               (dist(a,b) < EPS && a.y < b.y-EPS); });
      return dist(p[1], p[2]) < EPS ? p[1] : null; }
    return null; }
  double s = Ds / D, t = Dt / D;
  if (seg && (min(s,t)<-EPS||max(s,t)>1+EPS)) return null;
  return point(a.x + s * ab.x, a.y + s * ab.y); }
/* double A = cross(d-a, b-a), B = cross(c-a, b-a);
return (B*d - A*c)/(B - A); */
