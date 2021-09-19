const int MAX_KIDS = 2;
const char BASE = '0';  // 'a' or 'A'
struct trie {
  int val, cnt;
  std::vector<trie*> kids;
  trie () : val(-1), cnt(0), kids(MAX_KIDS, NULL) {}
  trie (int val) : val(val), cnt(0), kids(MAX_KIDS, NULL) {}
  trie (int val, int cnt, std::vector<trie*> &n_kids) :
    val(val), cnt(cnt), kids(n_kids) {}
  trie *insert(std::string &s, int i, int n) {
    trie *n_node = new trie(val, cnt+1, kids);
    if (i == n) return n_node;
    if (!n_node->kids[s[i]-BASE])
      n_node->kids[s[i]-BASE] = new trie(s[i]);
    n_node->kids[s[i]-BASE] =
      n_node->kids[s[i]-BASE]->insert(s, i+1, n);
    return n_node; } };
// max xor on a binary trie from version `a+1` to `b` (b > a):
int get_max_xor(trie *a, trie *b, int x) {
  int ans = 0;
  for (int i = MAX_BITS; i >= 0; --i) {
    // don't flip the bit for min xor
    int u = ((x & (1 << i)) > 0) ^ 1;
    int res_cnt = (b and b->kids[u] ? b->kids[u]->cnt : 0) -
                  (a and a->kids[u] ? a->kids[u]->cnt : 0);
    if (res_cnt == 0) u ^= 1;
    ans ^= (u << i);
    if (a) a = a->kids[u];
    if (b) b = b->kids[u]; }
  return ans; }
