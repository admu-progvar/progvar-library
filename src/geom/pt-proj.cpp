point proj(point p, point v) {
  // project point p onto a vector v (2D & 3D)
  return dot(p, v) / norm(v) * v; }
point projLine(point p, point a, point b) {
  // project point p onto line ab (2D & 3D)
  return a + dot(p-a, b-a) / norm(b-a) * (b-a); }
point projSeg(point p, point a, point b) {
  // project point p onto segment ab (2D & 3D)
  double s = dot(p-a, b-a) / norm(b-a);
  return a + min(1.0, max(0.0, s)) * (b-a); }
point projPlane(point p, double a, double b,
                double c, double d) {
  // project p onto plane ax+by+cz+d=0 (3D)
  // same as: o + p - project(p - o, n);
  double k = -d / (a*a + b*b + c*c);
  point o(a*k, b*k, c*k), n(a, b, c);
  point v(p.x-o.x, p.y-o.y, p.z-o.z);
  double s = dot(v, n) / dot(n, n);
  return point(o.x + p.x + s * n.x, o.y +
               p.y +s * n.y, o.z + p.z + s * n.z); }
