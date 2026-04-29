
import math

# 计算约数和
def divisor_sum(n: int) -> int:
    if n <= 1:
        return 0
    s = 1
    r = int(math.sqrt(n))
    for i in range(2, r+1):
        if n % i == 0:
            q = n // i
            s += q
            if q != i:
                s += i
    return s


if __name__ == "__main__":
    s = int(input().strip())

    MAX = 200000  # 足够覆盖本题所需的“第一对”搜索范围
    spd = [0] * (MAX + 1)

    # 筛法预处理真约数和：对每个 d，把 d 加到 2d,3d,... 上
    for d in range(1, MAX // 2 + 1):
        step = d
        start = d * 2
        for multiple in range(start, MAX + 1, step):
            spd[multiple] += d

    for a in range(s, MAX + 1):
        b = spd[a]
        if b == a or b == 0:
            continue

        if b <= MAX:
            if spd[b] == a and b != a:
                print(a, b)
                exit(0)
        else:
            # 罕见兜底：b 超过预处理范围，用 sqrt 计算互验
            if sum_proper_divisors_sqrt(b) == a:
                print(a, b)
                exit(0)

