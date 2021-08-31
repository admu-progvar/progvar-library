point bary(point A, point B, point C,
           double a, double b, double c) {
  return (A*a + B*b + C*c) / (a + b + c); }
point trilinear(point A, point B, point C,
                double a, double b, double c) {
  return bary(A,B,C,abs(B-C)*a,
              abs(C-A)*b,abs(A-B)*c); }
point centroid(point A, point B, point C) {
  return bary(A, B, C, 1, 1, 1); }
point circumcenter(point A, point B, point C) {
  double a=norm(B-C), b=norm(C-A), c=norm(A-B);
  return bary(A,B,C,a*(b+c-a),b*(c+a-b),c*(a+b-c)); }
point orthocenter(point A, point B, point C) {
  return bary(A,B,C, tan(angle(B,A,C)),
              tan(angle(A,B,C)), tan(angle(A,C,B))); }
point incenter(point A, point B, point C) {
  return bary(A,B,C,abs(B-C),abs(A-C),abs(A-B)); }
// incircle radius given the side lengths a, b, c
double inradius(double a, double b, double c) {
  double s = (a + b + c) / 2;
  return sqrt(s * (s-a) * (s-b) * (s-c)) / s; }
point excenter(point A, point B, point C) {
  double a = abs(B-C), b = abs(C-A), c = abs(A-B);
  return bary(A, B, C, -a, b, c); }
  // return bary(A, B, C, a, -b, c);
  // return bary(A, B, C, a, b, -c);
point brocard(point A, point B, point C) {
  double a = abs(B-C), b = abs(C-A), c = abs(A-B);
  return bary(A,B,C,c/b*a,a/c*b,b/a*c); // CCW
  // return bary(A,B,C,b/c*a,c/a*b,a/b*c); // CW }
point symmedian(point A, point B, point C) {
  return bary(A,B,C,norm(B-C),norm(C-A),norm(A-B)); }
