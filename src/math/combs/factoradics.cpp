// use fenwick tree add, sum, and low code
typedef long long LL;
void factoradic(int arr[], int n) { // 0 to n-1
    for (int i = 0; i <=n; i++) fen[i] = 0;
    for (int i = 1; i < n; i++) add(i, 1);
    for (int i = 0; i < n; i++) {
    int s = sum(arr[i]);
    add(arr[i], -1); arr[i] = s;
    }}
void permute(int arr[], int n) { // factoradic to perm
    for (int i = 0; i <=n; i++) fen[i] = 0;
    for (int i = 1; i < n; i++) add(i, 1);
    for (int i = 0; i < n; i++) {
    arr[i] = low(arr[i] - 1);
    add(arr[i], -1);
    }}