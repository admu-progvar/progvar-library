struct poly {
    double a, b;
    poly(double a=0, double b=0): a(a), b(b) {}
    poly operator+(const poly& p) const {
        return poly(a + p.a, b + p.b);}
    poly operator-(const poly& p) const {
        return poly(a - p.a, b - p.b);}
    poly operator*(const poly& p) const {
        return poly(a*p.a - b*p.b, a*p.b + b*p.a);}
};
void fft(poly in[], poly p[], int n, int s) {
    if (n < 1) return;
    if (n == 1) {p[0] = in[0]; return;}
    n >>= 1; fft(in, p, n, s << 1);
    fft(in + s, p + n, n, s << 1);
    poly w(1), wn(cos(M_PI/n), sin(M_PI/n));
    for (int i = 0; i < n; ++i) {
        poly even = p[i], odd = p[i + n];
        p[i] = even + w * odd;
        p[i + n] = even - w * odd;
        w = w * wn;
    }
}
void fft(poly p[], int n) {
    poly *f = new poly[n]; fft(p, f, n, 1);
    copy(f, f + n, p); delete[] f;
}
void inverse_fft(poly p[], int n) {
    for(int i=0; i<n; i++) {p[i].b *= -1;} fft(p, n);
    for(int i=0; i<n; i++) {p[i].a/=n; p[i].b/= -1*n;}
}
