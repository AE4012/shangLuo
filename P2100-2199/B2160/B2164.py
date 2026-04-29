
MOD = 10**9 + 7

if __name__ == "__main__":
    n, m = map(int, input().split())
    # 从 n 个不同的元素中选择 m 个元素的方案数
    # 组合数公式：C(n, m) = n! / (m! * (n - m)!)
    # 输出一个整数，表示组合数对10**9+7取模的结果
    fengzi = 1
    fengmu = 1

    # 组合数公式：C(n, m) = n! / (m! * (n - m)!)
    if m > n - m:
        mid1 = m
        mid2 = n - m
    else:
        mid1 = n - m
        mid2 = m
    for i in range(mid1+1, n+1):
        fengzi = fengzi*i
    for i in range(1, mid2+1):
        fengmu = fengmu*i

    # print(fengzi)
    # print(fengmu)
    print(fengzi//fengmu % MOD)

    

    