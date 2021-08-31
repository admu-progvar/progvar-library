double angle(point a, point b, point c) {
  // angle formed by abc in radians: PI < x <= PI
  return abs(remainder(arg(a-b) - arg(c-b), 2*PI)); }
point rotate(point p, point a, double d) {
  //rotate point a about pivot p CCW at d radians
  return p + (a - p) * point(cos(d), sin(d)); }
