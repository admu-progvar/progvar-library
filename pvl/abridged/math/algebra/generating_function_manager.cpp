const int DEPTH = 19;
const int ARR_DEPTH = (1<<DEPTH); //approx 5x10^5
const int SZ = 12;
ll temp[SZ][ARR_DEPTH+1];
const ll MOD = 998244353;
struct GF_Manager {
  int tC = 0;
  std::stack<int> to_be_freed;
  const static ll DEPTH = 23;
  ll prim[DEPTH+1], prim_inv[DEPTH+1], two_inv[DEPTH+1];
  ll mod_pow(ll base, ll exp) {
    if(exp==0) return 1;
    if(exp&1) return (base*mod_pow(base,exp-1))%MOD;
    else return mod_pow((base*base)%MOD, exp/2); }
  void set_up_primitives() {
    prim[DEPTH] = 31;
    prim_inv[DEPTH] = mod_pow(prim[DEPTH], MOD-2);
    two_inv[DEPTH] = mod_pow(1<<DEPTH,MOD-2);
    for(int n = DEPTH-1; n >= 0; n--) {
      prim[n] = (prim[n+1]*prim[n+1])%MOD;
      prim_inv[n] = mod_pow(prim[n],MOD-2);
      two_inv[n] = mod_pow(1<<n,MOD-2); } }
  GF_Manager(){ set_up_primitives(); }
  void start_claiming(){ to_be_freed.push(0); }
  ll* claim(){
    ++to_be_freed.top(); assert(tC < SZ); return temp[tC++]; }
  void end_claiming(){tC-=to_be_freed.top(); to_be_freed.pop();}
  void NTT(ll A[], int n, ll t[],
           bool is_inverse=false, int offset=0) {
    if (n==0)  return;
    //Put the evens first, then the odds
    for (int i = 0; i < (1<<(n-1)); i++) {
      t[i] = A[offset+2*i];
      t[i+(1<<(n-1))] = A[offset+2*i+1]; }
    for(int i = 0; i < (1<<n); i++)
      A[offset+i] = t[i];
    NTT(A, n-1, t, is_inverse, offset);
    NTT(A, n-1, t, is_inverse, offset+(1<<(n-1)));
    ll w1 = (is_inverse ? prim_inv[n] : prim[n]), w = 1;
    for (int i = 0; i < (1<<(n-1)); i++, w=(w*w1)%MOD) {
      t[i] = (A[offset+i] + w*A[offset+(1<<(n-1))+i])%MOD;
      t[i+(1<<(n-1))] = (A[offset+i]-
                         w*A[offset+(1<<(n-1))+i])%MOD; }
    for (int i = 0; i < (1<<n); i++) A[offset+i] = t[i];
  }
  int add(ll A[], int an, ll B[], int bn, ll C[]) {
    int cn = 0;
    for(int i = 0; i < max(an,bn); i++) {
      C[i] = A[i]+B[i];
      if(C[i] <= -MOD)  C[i] += MOD;
      if(MOD <= C[i])   C[i] -= MOD;
      if(C[i]!=0)       cn = i; }
    return cn; }
  int subtract(ll A[], int an, ll B[], int bn, ll C[]) {
    int cn = 0;
    for(int i = 0; i < max(an,bn); i++) {
      C[i] = A[i]-B[i];
      if(C[i] <= -MOD)  C[i] += MOD;
      if(MOD <= C[i])   C[i] -= MOD;
      if(C[i]!=0)       cn = i; }
    return cn+1; }
  int scalar_mult(ll v, ll A[], int an, ll C[]) {
    for(int i = 0; i < an; i++) C[i] = (v*A[i])%MOD;
    return v==0 ? 0 : an; }
  int mult(ll A[], int an, ll B[], int bn, ll C[]) {
    start_claiming();
    // make sure you've called setup prim first
    // note: an and bn refer to the *number of items in
    // each array*, NOT the degree of the largest term
    int n, degree = an+bn-1;
    for(n=0; (1<<n) < degree; n++);
    ll *tA = claim(), *tB = claim(), *t = claim();
    copy(A,A+an,tA); fill(tA+an,tA+(1<<n),0);
    copy(B,B+bn,tB); fill(tB+bn,tB+(1<<n),0);
    NTT(tA,n,t);
    NTT(tB,n,t);
    for(int i = 0; i < (1<<n); i++)
      tA[i] = (tA[i]*tB[i])%MOD;
    NTT(tA,n,t,true);
    scalar_mult(two_inv[n],tA,degree,C);
    end_claiming();
    return degree; }
  int reciprocal(ll F[], int fn, ll R[]) {
    start_claiming();
    ll *tR = claim(), *tempR = claim();
    int n;  for(n=0; (1<<n) < fn; n++);
    fill(tempR,tempR+(1<<n),0);
    tempR[0] = mod_pow(F[0],MOD-2);
    for (int i = 1; i <= n; i++) {
      mult(tempR,1<<i,F,1<<i,tR);
      tR[0] -= 2;
      scalar_mult(-1,tR,1<<i,tR);
      mult(tempR,1<<i,tR,1<<i,tempR); }
    copy(tempR,tempR+fn,R);
    end_claiming();
    return n; }
  int quotient(ll F[], int fn, ll G[], int gn, ll Q[]) {
    start_claiming();
    ll* revF = claim();
    ll* revG = claim();
    ll* tempQ = claim();
    copy(F,F+fn,revF); reverse(revF,revF+fn);
    copy(G,G+gn,revG); reverse(revG,revG+gn);
    int qn = fn-gn+1;
    reciprocal(revG,qn,revG);
    mult(revF,qn,revG,qn,tempQ);
    reverse(tempQ,tempQ+qn);
    copy(tempQ,tempQ+qn,Q);
    end_claiming();
    return qn; }
  int mod(ll F[], int fn, ll G[], int gn, ll R[]) {
    start_claiming();
    ll *Q = claim(), *GQ = claim();
    int qn = quotient(F, fn, G, gn, Q);
    int gqn = mult(G, gn, Q, qn, GQ);
    int rn = subtract(F, fn, GQ, gqn, R);
    end_claiming();
    return rn; }
  ll horners(ll F[], int fn, ll xi) {
    ll ans = 0;
    for(int i = fn-1; i >= 0; i--)
      ans = (ans*xi+F[i]) % MOD;
    return ans; } };
GF_Manager gfManager;
ll split[DEPTH+1][2*(ARR_DEPTH)+1];
ll Fi[DEPTH+1][2*(ARR_DEPTH)+1];
int bin_splitting(ll a[], int l, int r, int s=0, int offset=0) {
  if(l == r) {
    split[s][offset] = -a[l]; //x^0
    split[s][offset+1] = 1; //x^1
    return 2; }
  int m = (l+r)/2;
  int sz = m-l+1;
  int da = bin_splitting(a, l, m, s+1, offset);
  int db = bin_splitting(a, m+1, r, s+1, offset+(sz<<1));
  return gfManager.mult(split[s+1]+offset, da,
    split[s+1]+offset+(sz<<1), db, split[s]+offset); }
void multipoint_eval(ll a[], int l, int r, ll F[], int fn,
  ll ans[], int s=0, int offset=0) {
    if(l == r) {
      ans[l] = gfManager.horners(F,fn,a[l]);
      return; }
    int m = (l+r)/2;
    int sz = m-l+1;
    int da = gfManager.mod(F, fn, split[s+1]+offset,
      sz+1, Fi[s]+offset);
    int db = gfManager.mod(F, fn, split[s+1]+offset+(sz<<1),
      r-m+1, Fi[s]+offset+(sz<<1));
    multipoint_eval(a,l,m,Fi[s]+offset,da,ans,s+1,offset);
    multipoint_eval(a,m+1,r,Fi[s]+offset+(sz<<1),
      db,ans,s+1,offset+(sz<<1));
}
