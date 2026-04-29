import sys
input = sys.stdin.readline

n, V = map(int, input().split())

dp = [0] * (V + 1)

for _ in range(n):
    w, val = map(int, input().split())
    
    # 完全背包：正序枚举
    for j in range(w, V + 1):
        dp[j] = max(dp[j], dp[j - w] + val)

print(dp[V])