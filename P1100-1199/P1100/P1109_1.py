import sys

if __name__ == "__main__":
    n = int(input().strip())
    stu_group = list(map(int, input().strip().split()))
    L, R = map(int, input().strip().split())

    # 先判断是否满足条件
    stu_all = sum(stu_group)
    if stu_all < L*n or stu_all > R*n:
        print(-1)
        sys.exit(0)

    stu_target = []

    # 将值修改更换为离目标值最近的数
    for i in range(n):
        stu_target.append(min(max(L, stu_group[i]), R))

    base = sum(abs(a-b) for a, b in zip(stu_group, stu_target))

    delta = stu_all - sum(stu_target)
    ans = (base + abs(delta)) // n
    print(ans)