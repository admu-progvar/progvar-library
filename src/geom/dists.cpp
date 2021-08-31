double distPtLine(point p, double a, double b, double c) {
  // dist from point p to line ax+by+c=0
  return abs(a*p.x + b*p.y + c) / sqrt(a*a + b*b);}
double distPtLine(point p, point a, point b) {
  // dist from point p to line ab
  return abs((a.y - b.y) * (p.x - a.x) +
         (b.x - a.x) * (p.y - a.y)) /
         hypot(a.x - b.x, a.y - b.y);}
double distPtPlane(point p, double a, double b,
      double c, double d) {
  // distance to 3D plane ax + by + cz + d = 0
  return (a*p.x+b*p.y+c*p.z+d)/sqrt(a*a+b*b+c*c); }
/*! // distance between 3D lines AB & CD (untested)
double distLine3D(point A,point B,point C,point D){
  point u = B - A, v = D - C, w = A - C;
  double a = dot(u, u), b = dot(u, v);
  double c = dot(v, v), d = dot(u, w);
  double e = dot(v, w), det = a*c - b*b;
  double s = det < EPS ? 0.0 : (b*e - c*d) / det;
  double t = det < EPS
    ? (b > c ? d/b : e/c) // parallel
    : (a*e - b*d) / det;
  point top = A + u * s, bot = w - A - v * t;
  return dist(top, bot);
} // dist<EPS: intersection     */
