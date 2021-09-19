int par[N*2+1], child[N*2+1][128];
int len[N*2+1], node[N*2+1], cs[N*2+1], size;
long long cnt[N + 2]; // count can be very large
int newNode(int p = -1) {
  cnt[size] = 0; par[size] = p;
  len[size] = (p == -1 ? 0 : len[p] + 2);
  memset(child[size], -1, sizeof child[size]);
  return size++; }
int get(int i, char c) {
  if (child[i][c] == -1) child[i][c] = newNode(i);
  return child[i][c]; }
void manachers(char s[]) {
  int n = strlen(s), cn = n * 2 + 1;
  for (int i = 0; i < n; i++) {
    cs[i * 2] = -1; cs[i * 2 + 1] = s[i]; }
  size = n * 2;
  int odd = newNode(), even = newNode();
  int cen = 0, rad = 0, L = 0, R = 0;
  size = 0; len[odd] = -1;
  for (int i = 0; i < cn; i++)
    node[i] = (i % 2 == 0 ? even : get(odd, cs[i]));
  for (int i = 1; i < cn; i++) {
    if (i > rad) { L = i - 1; R = i + 1; }
    else {
      int M = cen * 2 - i; // retrieve from mirror
      node[i] = node[M];
      if (len[node[M]] < rad - i) L = -1;
      else {
        R = rad + 1; L = i * 2 - R;
        while (len[node[i]] > rad - i)
          node[i] = par[node[i]]; } } // expand palindrome
    while (L >= 0 && R < cn && cs[L] == cs[R]) {
        if (cs[L] != -1) node[i] = get(node[i],cs[L]);
        L--, R++; }
    cnt[node[i]]++;
    if (i + len[node[i]] > rad) {
      rad = i + len[node[i]]; cen = i; } }
  for (int i = size - 1; i >= 0; --i)
  cnt[par[i]] += cnt[i]; // update parent count }
int countUniquePalindromes(char s[]) {
  manachers(s); return size; }
int countAllPalindromes(char s[]) {
  manachers(s); int total = 0;
  for (int i = 0; i < size; i++) total += cnt[i];
  return total; }
// longest palindrome substring of s
std::string longestPalindrome(char s[]) {
  manachers(s);
  int n = strlen(s), cn = n * 2 + 1, mx = 0;
  for (int i = 1; i < cn; i++)
    if (len[node[mx]] < len[node[i]])
      mx = i;
  int pos = (mx - len[node[mx]]) / 2;
  return std::string(s + pos, s + pos + len[node[mx]]); }
