double dot(point a, point b) {
  return a.x * b.x + a.y * b.y; } // + a.z * b.z;
double cross(point a, point b) {
  return a.x * b.y - a.y * b.x; }
double cross(point a, point b, point c) {
  return cross(a, b) + cross(b, c) + cross(c, a); }
double cross3D(point a, point b) {
  return point(a.x*b.y - a.y*b.x, a.y*b.z -
               a.z*b.y, a.z*b.x - a.x*b.z); }
