typedef vector<double> Poly;
Poly Q, R; // quotient and remainder
void trim(Poly& A) { // remove trailing zeroes
    while (!A.empty() && abs(A.back()) < EPS)
    A.pop_back();
}
void divide(Poly A, Poly B) {
    if (B.size() == 0) throw exception();
    if (A.size() < B.size()) {Q.clear(); R=A; return;}
    Q.assign(A.size() - B.size() + 1, 0);
    Poly part;
    while (A.size() >= B.size()) {
        int As = A.size(), Bs = B.size();
        part.assign(As, 0);
        for (int i = 0; i < Bs; i++)
            part[As-Bs+i] = B[i];
        double scale = Q[As-Bs] = A[As-1] / part[As-1];
        for (int i = 0; i < As; i++)
            A[i] -= part[i] * scale;
        trim(A);
    } R = A; trim(Q); }
