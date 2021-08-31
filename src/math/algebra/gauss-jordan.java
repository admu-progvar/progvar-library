boolean gaussJordan(double A[][]) {
    int n = A.length, m = A[0].length;
    boolean singular = false;
    // double determinant = 1;
    for (int i=0, p=0; i<n && p<m; i++, p++) {
        for (int k = i + 1; k < n; k++) {
            if (Math.abs(A[k][p]) > EPS) { // swap
            // determinant *= -1;
            double t[]=A[i]; A[i]=A[k]; A[k]=t;
            break;
            }
        }
        // determinant *= A[i][p];
        if (Math.abs(A[i][p]) < EPS)
            { singular = true; i--; continue; }
        for (int j = m-1; j >= p; j--) A[i][j]/= A[i][p];
        for (int k = 0; k < n; k++) {
            if (i == k) continue;
            for (int j = m-1; j >= p; j--)
                A[k][j] -= A[k][p] * A[i][j];
        }
    } return !singular; }
