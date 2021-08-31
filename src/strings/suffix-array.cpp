int n, equiv[N+1], suffix[N+1];
ii equiv_pair[N+1];
string T;
void make_suffix_array(string& s) {
  if (s.back()!='$') s += '$';
  n = s.length();
  for (int i = 0; i < n; i++)
    suffix[i] = i;
  sort(suffix,suffix+n,[&s](int i, int j){return s[i] < s[j];});
  int sz = 0;
  for(int i = 0; i < n; i++){
    if(i==0 || s[suffix[i]]!=s[suffix[i-1]])
      ++sz;
    equiv[suffix[i]] = sz; }
  for (int t = 1; t < n; t<<=1) {
    for (int i = 0; i < n; i++)
      equiv_pair[i] = {equiv[i],equiv[(i+t)%n]};
    sort(suffix, suffix+n, [](int i, int j) {
         return equiv_pair[i] < equiv_pair[j];});
    int sz = 0;
    for (int i = 0; i < n; i++) {
      if(i==0 || equiv_pair[suffix[i]]!=equiv_pair[suffix[i-1]])
        ++sz;
      equiv[suffix[i]] = sz; } } }
int count_occurences(string& G) { // in string T
  int L = 0, R = n-1;
  for (int i = 0; i < G.length(); i++){
    // lower/upper = first/last time G[i] is
    // the ith character in suffixes from [L,R]
    std::tie(L,R) = {lower(G[i],i,L,R), upper(G[i],i,L,R)};
    if (L==-1 && R==-1) return 0; }
  return R-L+1; }
