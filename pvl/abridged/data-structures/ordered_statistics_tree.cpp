#include <ext/pb_ds/assoc_container.hpp> // for rope ds:
#include <ext/pb_ds/tree_policy.hpp>     // <ext/rope>
using namespace __gnu_pbds;              // __gnu_cxx;
template <typename T>
using index_set = tree<T, null_type, std::less<T>,
splay_tree_tag, tree_order_statistics_node_update>;
// indexed_set<int> t; t.insert(...);    // rope<int> v;
// t.find_by_order(index); // 0-based    // v.substr(l,r-l+1);
// t.order_of_key(key);                  // v.mutable_begin();
