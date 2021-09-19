double greatCircleDist(double lat1, double long1,
    double lat2, double long2, double R) {
  long1 *= PI / 180; lat1 *= PI / 180; // to radians
  long2 *= PI / 180; lat2 *= PI / 180;
  return R*acos(sin(lat1)*sin(lat2) +
         cos(lat1)*cos(lat2)*cos(abs(long1 - long2))); }
// another version, using actual (x, y, z)
double greatCircleDist(point a, point b) {
  return atan2(abs(cross3D(a, b)), dot3D(a, b)); }
