/*
Find the area of any 2D polygon given as points in $O(n)$.
*/
double area(point p[], int n) {
  double a = 0;
  for (int i = 0, j = n - 1; i < n; j = i++)
    a += cross(p[i], p[j]);
  return abs(a) / 2; }
