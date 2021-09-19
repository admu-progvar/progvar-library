typedef std::vector<bool> vb;
struct point3D {
  ll x, y, z;
  point3D(ll x = 0, ll y = 0, ll z = 0) : x(x), y(y), z(z) {}
  point3D operator-(const point3D &o) const {
    return point3D(x - o.x, y - o.y, z - o.z); }
  point3D cross(const point3D &o) const {
    return point3D(y*o.z-z*o.y, z*o.x-x*o.z, x*o.y-y*o.x); }
  ll dot(const point3D &o) const {
    return x*o.x + y*o.y + z*o.z; }
  bool operator==(const point3D &o) const {
    return std::tie(x, y, z) == std::tie(o.x, o.y, o.z); }
  bool operator<(const point3D &o) const {
    return std::tie(x, y, z) < std::tie(o.x, o.y, o.z); } };
struct face {
  std::vector<int> p_idx;
  point3D q; };
std::vector<face> convex_hull_3D(std::vector<point3D> &points) {
  int n = points.size();
  std::vector<face> faces;
  std::vector<vb> dead(points.size(), vb(points.size(), true));
  auto add_face = [&](int a, int b, int c) {
    faces.push_back({{a, b, c},
      (points[b] - points[a]).cross(points[c] - points[a])});
    dead[a][b] = dead[b][c] = dead[c][a] = false; };
  add_face(0, 1, 2);
  add_face(0, 2, 1);
  for (int i = 3; i < n; ++i) {
    std::vector<face> faces_inv;
    for(face &f : faces) {
      if ((points[i] - points[f.p_idx[0]]).dot(f.q) > 0)
        for (int j = 0; j < 3; ++j)
          dead[f.p_idx[j]][f.p_idx[(j+1)%3]] = true;
      else
        faces_inv.push_back(f); }
    faces.clear();
    for(face &f : faces_inv) {
      for (int j = 0; j < 3; ++j) {
        int a = f.p_idx[j], b = f.p_idx[(j + 1) % 3];
        if(dead[b][a])
          add_face(b, a, i); } }
    faces.insert(
      faces.end(), faces_inv.begin(), faces_inv.end()); }
  return faces; }
