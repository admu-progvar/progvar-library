int interior(point p[], int n) {
  return area(p,n) - boundary(p,n) / 2 + 1; }
int boundary(point p[], int n) {
  int ans = 0;
  for (int i = 0, j = n - 1; i < n; j = i++)
    ans += gcd(p[i].x - p[j].x, p[i].y - p[j].y);
  return ans; }
