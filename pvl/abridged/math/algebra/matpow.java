long[][] power(long B[][], long e) {
    int n = B.length;
    long ans[][]= new long[n][n];
    for (int i = 0; i < n; i++) ans[i][i] = 1;
    while (e > 0) {
        if (e % 2 == 1) ans = multiply(ans, b);
        b = multiply(b, b); e /= 2;
    } return ans;}
