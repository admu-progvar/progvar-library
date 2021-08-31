struct cartree {
  typedef struct _Node {
    int node_val, subtree_val, delta, prio, size;
    _Node *l, *r;
    _Node(int val) : node_val(val), subtree_val(val),
        delta(0), prio((rand()<<16)^rand()), size(1),
        l(NULL), r(NULL) {}
    ~_Node() { delete l; delete r; }
  } *Node;
  int get_subtree_val(Node v) {
    return v ? v->subtree_val : 0;  }
  int get_size(Node v) { return v ? v->size : 0; }
  void apply_delta(Node v, int delta) {
    if (!v) return;
    v->delta += delta;
    v->node_val += delta;
    v->subtree_val += delta * get_size(v); }
  void push_delta(Node v) {
    if (!v) return;
    apply_delta(v->l, v->delta);
    apply_delta(v->r, v->delta);
    v->delta = 0; }
  void update(Node v) {
    if (!v) return;
    v->subtree_val = get_subtree_val(v->l) + v->node_val
                   + get_subtree_val(v->r);
    v->size = get_size(v->l) + 1 + get_size(v->r); }
  Node merge(Node l, Node r) {
    push_delta(l);    push_delta(r);
    if (!l || !r)   return l ? l : r;
    if (l->size <= r->size) {
      l->r = merge(l->r, r);
      update(l);
      return l;
    } else {
      r->l = merge(l, r->l);
      update(r);
      return r; } }
  void split(Node v, int key, Node &l, Node &r) {
    push_delta(v);
    l = r = NULL;
    if (!v)     return;
    if (key <= get_size(v->l)) {
      split(v->l, key, l, v->l);
      r = v;
    } else {
      split(v->r, key - get_size(v->l) - 1, v->r, r);
      l = v; }
    update(v); }
  Node root;
public:
  cartree() : root(NULL) {}
  ~cartree() { delete root; }
  int get(Node v, int key) {
    push_delta(v);
    if (key < get_size(v->l))
      return get(v->l, key);
    else if (key > get_size(v->l))
      return get(v->r, key - get_size(v->l) - 1);
    return v->node_val; }
  int get(int key) { return get(root, key); }
  void insert(Node item, int key) {
    Node l, r;
    split(root, key, l, r);
    root = merge(merge(l, item), r); }
  void insert(int key, int val) {
    insert(new _Node(val), key); }
  void erase(int key) {
    Node l, m, r;
    split(root, key + 1, m, r);
    split(m, key, l, m);
    delete m;
    root = merge(l, r); }
  int query(int a, int b) {
    Node l1, r1;
    split(root, b+1, l1, r1);
    Node l2, r2;
    split(l1, a, l2, r2);
    int res = get_subtree_val(r2);
    l1 = merge(l2, r2);
    root = merge(l1, r1);
    return res; }
  void update(int a, int b, int delta) {
    Node l1, r1;
    split(root, b+1, l1, r1);
    Node l2, r2;
    split(l1, a, l2, r2);
    apply_delta(r2, delta);
    l1 = merge(l2, r2);
    root = merge(l1, r1); }
  int size() { return get_size(root); } };
