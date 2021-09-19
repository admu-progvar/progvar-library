// insert inside code for finding articulation points
graph build_block_cut_tree() {
  int bct_n = articulation_points.size() + comps.size();
  vi block_id(n), is_art(n, 0);
  graph tree(bct_n);
  for (int i = 0; i < articulation_points.size(); ++i) {
    block_id[articulation_points[i]] = i;
    is_art[articulation_points[i]] = 1; }
  for (int i = 0; i < comps.size(); ++i) {
    int id = i + articulation_points.size();
    for (int u : comps[i])
      if (is_art[u])  tree.add_edge(block_id[u], id);
      else            block_id[u] = id; }
  return tree; }
