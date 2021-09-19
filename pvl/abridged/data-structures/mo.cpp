struct query {
  int id, l, r; ll hilbert_index;
  query(int id, int l, int r) : id(id), l(l), r(r) {
    hilbert_index = hilbert_order(l, r, LOGN, 0); }
  ll hilbert_order(int x, int y, int pow, int rotate) {
    if (pow == 0) return 0;
    int hpow = 1 << (pow-1);
    int seg = ((x<hpow) ? ((y<hpow)?0:3) : ((y<hpow)?1:2));
    seg = (seg + rotate) & 3;
    const int rotate_delta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotate_delta[seg]) & 3;
    ll sub_sq_size = ll(1) << (2*pow - 2);
    ll ans = seg * sub_sq_size;
    ll add = hilbert_order(nx, ny, pow-1, nrot);
    ans += (seg==1 || seg==2) ? add : (sub_sq_size-add-1);
    return ans; }
  bool operator<(const query& other) const {
    return this->hilbert_index < other.hilbert_index; } };
std::vector<query> queries;
for(const query &q : queries) {  // [l,r] inclusive
  for(; r > q.r; r--)         update(r, -1);
  for(r = r+1; r <= q.r; r++) update(r);
  r--;
  for( ; l < q.l; l++)        update(l, -1);
  for(l = l-1; l >= q.l; l--) update(l);
  l++; }
