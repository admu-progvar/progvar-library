struct node {  int l, r, lid, rid, val;  };
struct segtree {
  node *nodes;
  int n, node_cnt = 0;
  segtree(int n, int capacity) {
    this->n = n;
    nodes = new node[capacity]; }
  int build (vi &ar, int l, int r) {
    if (l > r)  return -1;
    int id = node_cnt++;
    nodes[id].l = l;
    nodes[id].r = r;
    if (l == r) {
      nodes[id].lid = -1;
      nodes[id].rid = -1;
      nodes[id].val = ar[l];
    } else {
      int m = (l + r) / 2;
      nodes[id].lid = build(ar, l, m);
      nodes[id].rid = build(ar, m+1, r);
      nodes[id].val = nodes[nodes[id].lid].val +
                      nodes[nodes[id].rid].val; }
    return id; }
  int update(int id, int idx, int delta) {
    if (id == -1)
      return -1;
    if (idx < nodes[id].l or nodes[id].r < idx)
      return id;
    int nid = node_cnt++;
    nodes[nid].l = nodes[id].l;
    nodes[nid].r = nodes[id].r;
    nodes[nid].lid = update(nodes[id].lid, idx, delta);
    nodes[nid].rid = update(nodes[id].rid, idx, delta);
    nodes[nid].val = nodes[id].val + delta;
    return nid; }
  int query(int id, int l, int r) {
    if (r < nodes[id].l or nodes[id].r < l)
      return 0;
    if (l <= nodes[id].l and nodes[id].r <= r)
      return nodes[id].val;
    return query(nodes[id].lid, l, r) +
           query(nodes[id].rid, l, r); } };
