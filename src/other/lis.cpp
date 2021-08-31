vi lis(vi arr) {
  if (arr.empty()) return vi();
  vi seq, back(size(arr)), ans;
  rep(i,0,size(arr)) {
    int res = 0, lo = 1, hi = size(seq);
    while (lo <= hi) {
      int mid = (lo+hi)/2;
      if (arr[seq[mid-1]] < arr[i]) res = mid, lo = mid + 1;
      else hi = mid - 1; }
    if (res < size(seq)) seq[res] = i;
    else seq.push_back(i);
    back[i] = res == 0 ? -1 : seq[res-1]; }
  int at = seq.back();
  while (at != -1) ans.push_back(at), at = back[at];
  reverse(ans.begin(), ans.end());
  return ans; }
