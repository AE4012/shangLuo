import sys

def count_digits_upto(n: int):
    """
    Count occurrences of digits 0..9 in all numbers in [0, n].
    Returns list of length 10.
    """
    if n < 0:
        return [0]*10
    if n == 0:
        return [1,0,0,0,0,0,0,0,0,0]

    res = [0]*10
    i = 1  # current place value: 1, 10, 100, ...
    while i <= n:
        high = n // (i * 10)
        cur  = (n // i) % 10
        low  = n % i

        for d in range(10):
            # full cycles contribution
            res[d] += high * i

            # partial cycle contribution
            if cur > d:
                res[d] += i
            elif cur == d:
                res[d] += low + 1

        # remove leading-zero overcount at this position
        res[0] -= i

        i *= 10

    # we excluded number 0 completely by the leading-zero fix; add it back (since range includes 0)
    res[0] += 1
    return res

def main():
    data = sys.stdin.read().strip().split()
    if not data:
        return
    M, N = map(int, data[:2])

    a = count_digits_upto(N)
    b = count_digits_upto(M - 1)
    ans = [a[d] - b[d] for d in range(10)]
    print(" ".join(map(str, ans)))

if __name__ == "__main__":
    main()
