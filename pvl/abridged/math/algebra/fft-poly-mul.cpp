// note: c[] should have size of at least (an+bn)
int mult(int a[],int an,int b[],int bn,int c[]) {
    int n, degree = an + bn - 1;
    for (n = 1; n < degree; n <<= 1); // power of 2
    poly *A = new poly[n], *B = new poly[n];
    copy(a, a + an, A); fill(A + an, A + n, 0);
    copy(b, b + bn, B); fill(B + bn, B + n, 0);
    fft(A, n); fft(B, n);
    for (int i = 0; i < n; i++) A[i] = A[i] * B[i];
    inverse_fft(A, n);
    for (int i = 0; i < degree; i++)
        c[i] = int(A[i].a + 0.5); // same as round(A[i].a)
    delete[] A, B; return degree;
}
