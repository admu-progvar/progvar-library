long[][] multiply(long A[][], long B[][]) {
    int p = A.length, q = A[0].length, r = B[0].length;
    // if(q != B.length) throw new Exception(":(((");
    long AB[][] = new long[p][r];
    for (int i = 0; i < p; i++)
    for (int j = 0; j < q; j++)
    for (int k = 0; k < r; k++)
        (AB[i][k] += A[i][j] * B[j][k]) %= MOD;
    return AB; }
