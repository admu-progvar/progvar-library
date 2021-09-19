int f[N * 2];
int booth(string S) {
  S.append(S); // concatenate itself
  int n = S.length(), i, j, k = 0;
  memset(f, -1, sizeof(int) * n);
  for (j = 1; j < n; j++) {
    i = f[j-k-1];
    while (i != -1 && S[j] != S[k + i + 1]) {
      if (S[j] < S[k + i + 1]) k = j - i - 1;
      i = f[i];
    } if (i == -1 && S[j] != S[k + i + 1]) {
      if (S[j] < S[k + i + 1]) k = j;
      f[j - k] = -1;
    } else f[j - k] = i + 1;
  } return k; }
