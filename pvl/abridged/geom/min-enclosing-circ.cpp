std::pair<point, double> bounding_ball(point p[], int n){
  std::random_shuffle(p, p + n);
  point center(0, 0); double radius = 0;
  for (int i = 0; i < n; ++i) {
    if (dist(center, p[i]) > radius + EPS) {
      center = p[i]; radius = 0;
      for (int j = 0; j < i; ++j)
        if (dist(center, p[j]) > radius + EPS) {
          center.x = (p[i].x + p[j].x) / 2;
          center.y = (p[i].y + p[j].y) / 2;
          // center.z = (p[i].z + p[j].z) / 2;
          radius = dist(center, p[i]); // midpoint
          for (int k = 0; k < j; ++k)
            if (dist(center, p[k]) > radius + EPS) {
              center = circumcenter(p[i], p[j], p[k]);
              radius = dist(center, p[i]); } } } }
  return {center, radius}; }
