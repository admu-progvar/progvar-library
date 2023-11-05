
#include <vector>
#include "../pvl/data-structures/segtree_persistent_lazy.hpp"

#include <gtest/gtest.h>

TEST(PersistentLazySegtree, PersistentLazySegtree) {
  std::vector<pvl::segtree*> segtrees;

  // 0 0 0 0 0 0 0 0 0 0
  // 5 5 5 5 5 0 0 0 0 0
  // 5 5 8 8 8 3 3 0 0 0
  // 5 5 8 8 8 3 3 0 4 4
  segtrees.push_back(new pvl::segtree(0, 10));
  segtrees.push_back(segtrees.back()->update(0, 4, 5));
  segtrees.push_back(segtrees.back()->update(2, 6, 3));
  segtrees.push_back(segtrees.back()->update(8, 9, 4));

  std::vector<int> expected = {
    0, 0, 0, 0, 0,
    25, 20, 15, 10, 5,
    37, 35, 30, 22, 14,
    37, 35, 30, 26, 22
  };
  std::vector<int> queries;
  for (auto ptr : segtrees) {
    for (int i = 0; i < 5; ++i) {
      queries.push_back(ptr->query(i, i+5));
    }
  }

  EXPECT_EQ(expected, queries);
}
