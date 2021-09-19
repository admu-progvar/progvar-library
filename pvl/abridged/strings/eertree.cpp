struct node {
  int start, end, len, back_edge, *adj;
  node() {
    adj = new int[26];
    for (int i = 0; i < 26; ++i)  adj[i] = 0; }
  node(int start, int end, int len, int back_edge) :
       start(start), end(end), len(len), back_edge(back_edge) {
    adj = new int[26];
    for (int i = 0; i < 26; ++i)  adj[i] = 0; } };
struct eertree {
  int ptr, cur_node;
  std::vector<node> tree;
  eertree () {
    tree.push_back(node());
    tree.push_back(node(0, 0, -1, 1));
    tree.push_back(node(0, 0,  0, 1));
    cur_node = 1;
    ptr = 2; }
  int get_link(int temp, std::string &s, int i) {
    while (true) {
      int cur_len = tree[temp].len;
      // don't return immediately if you want to
      // get all palindromes; not recommended
      if (i-cur_len-1 >= 0 and s[i] == s[i-cur_len-1])
        return temp;
      temp = tree[temp].back_edge; }
    return temp; }
  void insert(std::string &s, int i) {
    int temp = cur_node;
    temp = get_link(temp, s, i);
    if (tree[temp].adj[s[i] - 'a'] != 0) {
      cur_node = tree[temp].adj[s[i] - 'a'];
      return; }
    ptr++;
    tree[temp].adj[s[i] - 'a'] = ptr;
    int len = tree[temp].len + 2;
    tree.push_back(node(i-len+1, i, len, 0));
    temp = tree[temp].back_edge;
    cur_node = ptr;
    if (tree[cur_node].len == 1) {
      tree[cur_node].back_edge = 2;
      return; }
    temp = get_link(temp, s, i);
    tree[cur_node].back_edge = tree[temp].adj[s[i]-'a']; }
  void insert(std::string &s) {
    for (int i = 0; i < s.size(); ++i)
      insert(s, i); } };
