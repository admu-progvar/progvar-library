struct node *null;
struct node {
  node *left, *right, *parent;
  bool reverse; int size, value;
  node*& get(int d) {return d == 0 ? left : right;}
  node(int v=0): reverse(0), size(0), value(v) {
  left = right = parent = null ? null : this; } };
struct SplayTree {
  node *root;
  SplayTree(int arr[] = NULL, int n = 0) {
    if (!null) null = new node();
    root = build(arr, n); }
  node* build(int arr[], int n) {
    if (n == 0) return null;
    int mid = n >> 1;
    node *p = new node(arr ? arr[mid] : 0);
    link(p, build(arr, mid), 0);
    link(p, build(arr? arr+mid+1 : NULL, n-mid-1), 1);
    pull(p); return p; }
  void pull(node *p) {
    p->size = p->left->size + p->right->size + 1; }
  void push(node *p) {
    if (p != null && p->reverse) {
      swap(p->left, p->right);
      p->left->reverse ^= 1;
      p->right->reverse ^= 1;
      p->reverse ^= 1; } }
  void link(node *p, node *son, int d) {
    p->get(d) = son;
    son->parent = p; }
  int dir(node *p, node *son) {
    return p->left == son ? 0 : 1; }
  void rotate(node *x, int d) {
    node *y = x->get(d), *z = x->parent;
    link(x, y->get(d ^ 1), d);
    link(y, x, d ^ 1);
    link(z, y, dir(z, x));
    pull(x); pull(y); }
  node* splay(node *p) {
    while (p->parent != null) {
      node *m = p->parent, *g = m->parent;
      push(g); push(m); push(p);
      int dm = dir(m, p), dg = dir(g, m);
      if (g == null) rotate(m, dm);
      else if (dm == dg) rotate(g, dg), rotate(m, dm);
      else rotate(m, dm), rotate(g, dg);
    } return root = p; }
  node* get(int k) {
    node *p = root;
    while (push(p), p->left->size != k) {
        if (k < p->left->size) p = p->left;
        else k -= p->left->size + 1, p = p->right; }
    return p == null ? null : splay(p); }
  void split(node *&r, int k) {
    if (k == 0) { r = root; root = null; return; }
    r = get(k - 1)->right;
    root->right = r->parent = null;
    pull(root); }
  void merge(node *r) {
    if (root == null) {root = r; return;}
    link(get(root->size - 1), r, 1);
    pull(root); }
  void assign(int k, int val) {
    get(k)->value = val; pull(root); }
  void reverse(int L, int R) {
    node *m, *r; split(r, R + 1); split(m, L);
    m->reverse ^= 1; push(m); merge(m); merge(r); }
  node* insert(int k, int v) {
    node *r; split(r, k);
    node *p = new node(v); p->size = 1;
    link(root, p, 1); merge(r);
    return p; }
  void erase(int k) {
    node *r, *m;
    split(r, k + 1); split(m, k);
    merge(r); delete m; } };
