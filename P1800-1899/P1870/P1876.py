import math

if __name__ == "__main__":
    n = int(input().strip())
    m = math.isqrt(n)
    ans = [str(i*i) for i in range(1, m+1)]

    print(" ".join(ans))   