#include "segtree.cpp"
struct LeqCounter {
  segtree **roots;
  LeqCounter(int *ar, int n) {
    std::vector<ii> nums;
    for (int i = 0; i < n; ++i)
      nums.push_back({ar[i], i});
    std::sort(nums.begin(), nums.end());
    roots = new segtree*[n];
    roots[0] = new segtree(0, n);
    int prev = 0;
    for (ii &e : nums) {
      for (int i = prev+1; i < e.first; ++i)
        roots[i] = roots[prev];
      roots[e.first] = roots[prev]->update(e.second, 1);
      prev = e.first; }
    for (int i = prev+1; i < n; ++i)
      roots[i] = roots[prev]; }
  int count(int i, int j, int x) {
    return roots[x]->query(i, j); } };
