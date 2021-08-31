// REQUIREMENT: list of primes pr[], see prime sieve
typedef long long LL;
int pre[N], q[N], path[N]; bool vis[N];
// perform BFS and return the last node visited
int bfs(int u, vector<int> adj[]) {
    memset(vis, 0, sizeof(vis));
    int head = 0, tail = 0;
    q[tail++] = u; vis[u] = true; pre[u] = -1;
    while (head != tail) {
        u = q[head]; if (++head == N) head = 0;
        for (int i = 0; i < adj[u].size(); ++i) {
            int v = adj[u][i];
            if (!vis[v]) {
                vis[v] = true; pre[v] = u;
                q[tail++] = v; if (tail == N) tail = 0;
            }}}
    return u;
} // returns the list of tree centers
vector<int> tree_centers(int r, vector<int> adj[]) {
    int size = 0;
    for (int u=bfs(bfs(r, adj), adj); u!=-1; u=pre[u])
        path[size++] = u;
    vector<int> med(1, path[size/2]);
    if (size % 2 == 0) med.push_back(path[size/2-1]);
    return med;
} // returns "unique hashcode" for tree with root u
LL rootcode(int u, vector<int> adj[], int p=-1, int d=15){
    vector<LL> k; int nd = (d + 1) % primes;
    for (int i = 0; i < adj[u].size(); ++i)
        if (adj[u][i] != p)
            k.push_back(rootcode(adj[u][i], adj, u, nd));
    sort(k.begin(), k.end());
    LL h = k.size() + 1;
    for (int i = 0; i < k.size(); ++i)
        h = h * pr[d] + k[i];
    return h;
} // returns "unique hashcode" for the whole tree
LL treecode(int root, vector<int> adj[]) {
    vector<int> c = tree_centers(root, adj);
    if (c.size()==1)
        return (rootcode(c[0], adj) << 1) | 1;
    return (rootcode(c[0],adj)*rootcode(c[1],adj))<<1;
} // checks if two trees are isomorphic
bool isomorphic(int r1, vector<int> adj1[], int r2,
                vector<int> adj2[], bool rooted = false) {
    if (rooted)
        return rootcode(r1, adj1) == rootcode(r2, adj2);
    return treecode(r1, adj1) == treecode(r2, adj2); }
