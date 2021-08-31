// sa[i]: ith smallest substring at s[sa[i]:]
// pos[i]: position of s[i:] in suffix array
int sa[N], pos[N], va[N], c[N], gap, n;
bool cmp(int i, int j) {
  return pos[i]!=pos[j] ? pos[i] < pos[j] : j < i; }
bool equal(int i, int j) {
  return pos[i] == pos[j] && i + gap < n &&
         pos[i + gap / 2] == pos[j + gap / 2]; }
void buildSA(string s) {
  s += '$'; n = s.length();
  for (int i = 0; i < n; i++){sa[i]=i; pos[i]=s[i];}
  sort (sa, sa + n, cmp);
  for (gap = 1; gap < n * 2; gap <<= 1) {
    va[sa[0]] = 0;
    for (int i = 1; i < n; i++) {
      int prev = sa[i - 1], next = sa[i];
      va[next] = equal(prev, next) ? va[prev] : i; }
    for (int i = 0; i < n; ++i) {
      pos[i] = va[i]; va[i] = sa[i]; c[i] = i; }
    for (int i = 0; i < n; i++) {
      int id = va[i] - gap;
      if (id >= 0) sa[c[pos[id]]++] = id; } } }
