std::multiset<int> adj[1010];
std::list<int> L;
std::list<int>::iterator euler(
  int at, int to, std::list<int>::iterator it
) {
  if (at == to) return it;
  L.insert(it, at), --it;
  while (!adj[at].empty()) {
    int nxt = *adj[at].begin();
    adj[at].erase(adj[at].find(nxt));
    adj[nxt].erase(adj[nxt].find(at));
    if (to == -1) {
      it = euler(nxt, at, it);
      L.insert(it, at);
      --it;
    } else {
      it = euler(nxt, to, it);
      to = -1; } }
  return it; }
// euler(0,-1,L.begin())
