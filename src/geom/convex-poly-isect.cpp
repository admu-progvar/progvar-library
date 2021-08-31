std::vector<point> convex_polygon_inter(
    point a[], int an, point b[], int bn) {
  point ans[an + bn + an*bn];
  int size = 0;
  for (int i = 0; i < an; ++i)
    if (inPolygon(a[i],b,bn) || onPolygon(a[i],b,bn))
      ans[size++] = a[i];
  for (int i = 0; i < bn; ++i)
    if (inPolygon(b[i],a,an) || onPolygon(b[i],a,an))
      ans[size++] = b[i];
  for (int i = 0, I = an - 1; i < an; I = i++)
    for (int j = 0, J = bn - 1; j < bn; J = j++) {
      try {
        point p=line_inter(a[i],a[I],b[j],b[J],true);
        ans[size++] = p;
      } catch (exception ex) {} }
  size = convex_hull(ans, size);
  return vector<point>(ans, ans + size); }
