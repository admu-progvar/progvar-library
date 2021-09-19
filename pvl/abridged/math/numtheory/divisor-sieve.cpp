int divisors[N]; // initially 0
void divisorSieve() {
  for (int i = 1; i < N; i++)
    for (int j = i; j < N; j += i)
      divisors[j]++; }
