import sys

def solve():
    data = sys.stdin.read().split()
    n ,V = int(data[0]), int(data[1])

    volume_value= []

    idx = 2
    for _ in range(n):
        w = int(data[idx])
        val = int(data[idx+1])
        c = int(data[idx+2])
        idx += 3

        k = 1
        while k <= c:
            volume_value.append((k*w, k*val))
            c -= k
            k *= 2 # 二进制拆分，每次增加的物品数量是前一次的两倍
        if c > 0:
            volume_value.append((w*c, val*c))
    
    dp = [0] * (V + 1)

    for new_w, new_val in volume_value:
        for j in range(V, new_w-1, -1):
            if dp[j-new_w] + new_val > dp[j]:
                dp[j] = dp[j-new_w] + new_val

    print(dp[V])


if __name__ == "__main__":
    solve()