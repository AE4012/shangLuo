import sys 

def solve():
    data = sys.stdin.read().split()
    n = int(data[0])
    list_a = [int(data[i]) for i in range(1, n+1)]

    # 前n项和
    profix_sum = [0] * (n+1)
    for i in range(1, n+1):
        profix_sum[i] = profix_sum[i-1] + list_a[i-1]

    m = int(data[n+1])
    idx = n+2
    for _ in range(m):
        l = int(data[idx])
        r = int(data[idx+1])
        idx += 2
        print(profix_sum[r]-profix_sum[l-1])


if __name__ == "__main__":
    solve()