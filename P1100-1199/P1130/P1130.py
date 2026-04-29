import sys

def solve():
    data = sys.stdin.buffer.read()
    n = len(data)
    idx = 0

    def next_int():
        nonlocal idx
        # skip non-digit
        while idx < n and data[idx] <= 32:
            idx += 1
        x = 0
        while idx < n and data[idx] > 32:
            x = x * 10 + (data[idx] - 48)
            idx += 1
        return x

    N = next_int()
    M = next_int()

    # 扁平存储：a[i*N + j] 对应第 i 组第 j 步（i,j 从 0 开始）
    total = N * M
    a = [0] * total
    for k in range(total):
        a[k] = next_int()

    # dp[i]：当前 step 落在 i 组的最小代价（i 0..M-1）
    dp = [0] * M
    ndp = [0] * M

    # step 0 初始化：dp[i] = a[i*N + 0]
    base = 0
    for i in range(M):
        dp[i] = a[base]
        base += N

    # step 1..N-1
    for j in range(1, N):
        # i=0 的 prev 是 M-1
        v0 = a[j]  # i=0 => index 0*N + j
        p0 = dp[0]
        pm = dp[M - 1]
        ndp0 = p0 if p0 < pm else pm
        ndp[0] = v0 + ndp0

        # i=1..M-1
        for i in range(1, M):
            v = a[i * N + j]
            x = dp[i]
            y = dp[i - 1]
            ndp[i] = v + (x if x < y else y)

        dp, ndp = ndp, dp

    # 答案
    ans = dp[0]
    for i in range(1, M):
        if dp[i] < ans:
            ans = dp[i]
    sys.stdout.write(str(ans))

if __name__ == "__main__":
    solve()
