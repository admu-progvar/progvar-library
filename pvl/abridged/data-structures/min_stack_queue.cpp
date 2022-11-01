struct min_stack {
  std::stack<ii> st;
  bool empty() { return st.empty(); }
  void add(int x) {
    int mn = st.empty() ? x : std::min(x, st.top().second);
    st.push({x, mn}); }
  void pop() { st.pop(); }
  int top() { return st.top().first; }
  int min() { return st.top().second; } };
struct min_queue {
  min_stack st1, st2;
  void add(int x) { st1.add(x); }
  void flip() {
    while (!st1.empty()) st2.add(st1.top()), st1.pop(); }
  void pop() { if (st2.empty()) flip(); st2.pop(); }
  int front() { if (st2.empty()) flip(); return st2.top(); }
  int min() { return std::min(st1.min(), st2.min()); } };
