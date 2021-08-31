double shamos(point p[], int n) {
  point *h = new point[n+1]; copy(p, p + n, h);
  int k = convex_hull(h, n); if (k <= 2) return 0;
  h[k] = h[0]; double d = HUGE_VAL;
  for (int i = 0, j = 1; i < k; ++i) {
    while (distPtLine(h[j+1], h[i], h[i+1]) >=
           distPtLine(h[j], h[i], h[i+1])) {
      j = (j + 1) % k; }
    d = min(d, distPtLine(h[j], h[i], h[i+1]));
  } return d; }
