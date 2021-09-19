const int N = 1000 * 1000; // number of steps
double simpson_integration(double a, double b){
  double h = (b - a) / N;
  double s = f(a) + f(b); // a = x_0 and b = x_2n
  for (int i = 1; i <= N - 1; ++i) {
    double x = a + h * i;
    s += f(x) * ((i & 1) ? 4 : 2); }
  s *= h / 3;
  return s; }
