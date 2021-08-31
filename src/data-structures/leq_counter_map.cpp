struct LeqCounter {
  std::map<int, segtree*> roots;
  std::set<int> neg_nums;
  LeqCounter(int *ar, int n) {
    std::vector<ii> nums;
    for (int i = 0; i < n; ++i) {
      nums.push_back({ar[i], i});
      neg_nums.insert(-ar[i]);
    }
    std::sort(nums.begin(), nums.end());
    roots[0] = new segtree(0, n);
    int prev = 0;
    for (ii &e : nums) {
      roots[e.first] = roots[prev]->update(e.second, 1);
      prev = e.first; } }
  int count(int i, int j, int x) {
    auto it = neg_nums.lower_bound(-x);
    if (it == neg_nums.end())   return 0;
    return roots[-*it]->query(i, j); } };
