struct state {/*...*/};
struct operation {/*...*/};
struct data_struct {
    state s;
    void apply_operation(operation &op) {
        /*...*/
        s = /*...*/; }
    void rollback(state &old_s) {
        /*...*/
        s = old_s; } };
struct segtree {
    int l, r;
    std::vector<operation> operations;
    segtree *left, *right;
    segtree(int l, int r) : l(l), r(r) {
        if (l == r) {
            left = right = NULL;
        } else {
            int m = (l + r) / 2;
            left = new segtree(l, m);
            right = new segtree(m + 1, r); } }
    void add_operation(int _l, int _r, operation &op) {
        if (_l <= l && r <= _r) {
            operations.push_back(op);
        } else if (_r < l || r < _l) {
            return;
        } else {
            left->add_operation(_l, _r, op);
            right->add_operation(_l, _r, op); } }
    void solve(data_struct &ds, std::vector<int> &ans) {
        state old_s = ds.s;
        for (operation &op : operations)
            ds.apply_operation(op);
        if (l == r) {
            ans[l] = /*...*/;
        } else {
            left->solve(ds, ans);
            right->solve(ds, ans); }
        ds.rollback(old_s); } };
