def fprime(n, p):
    # counts the number of prime divisors of n!
    pk, ans = p, 0
    while pk <= n:
        ans += n // pk
        pk *= p
    return ans
def granville(n, k, p, E):
    # n choose k (mod p^E)
    prime_pow = fprime(n, p) - fprime(k, p) - fprime(n - k, p)
    if prime_pow >= E:
        return 0
    e = E - prime_pow
    pe = p**e
    r, f = n - k, [1] * pe
    for i in range(1, pe):
        x = i
        if x % p == 0:
            x = 1
        f[i] = f[i - 1] * x % pe
    numer, denom, negate, ptr = 1, 1, 0, 0
    while n:
        if f[-1] != 1 and ptr >= e:
            negate ^= (n & 1) ^ (k & 1) ^ (r & 1)
        numer = numer * f[n % pe] % pe
        denom = denom * f[k % pe] % pe * f[r % pe] % pe
        n, k, r = n // p, k // p, r // p
        ptr += 1
    ans = numer * modinv(denom, pe) % pe
    if negate and (p != 2 or e < 3):
        ans = (pe - ans) % pe
    return mod(ans * p**prime_pow, p**E)
def choose(n, k, m):  # generalized (n choose k) mod m
    factors, x, p = [], m, 2
    while p * p <= x:
        e = 0
        while x % p == 0:
            e += 1
            x //= p
        if e:
            factors.append((p, e))
        p += 1
    if x > 1:
        factors.append((x, 1))
    crt_array = [granville(n, k, p, e) for p, e in factors]
    mod_array = [p**e for p, e in factors]
    return chinese_remainder(crt_array, mod_array)[0]
