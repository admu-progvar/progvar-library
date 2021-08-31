int f[MX+1]; // MX is maximum number of array
long long gcnt[MX+1]; // gcnt[G]: answer when gcd==G
long long C(int f) {return (1ll << f) - 1;}
// f: frequency count
// C(f): # of subsets of f elements (YOU CAN EDIT)
// Usage: int subsets_with_gcd_1 = gcnt[1];
void gcd_counter(int a[], int n) {
  memset(f, 0, sizeof f);
  memset(gcnt, 0, sizeof gcnt);
  int mx = 0;
  for (int i = 0; i < n; ++i) {
      f[a[i]] += 1;
      mx = max(mx, a[i]); }
  for (int i = mx; i >= 1; --i) {
    int add = f[i];
    long long sub = 0;
    for (int j = 2*i; j <= mx; j += i) {
      add += f[j];
      sub += gcnt[j]; }
    gcnt[i] = C(add) - sub; }}
