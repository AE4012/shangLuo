


if __name__ == "__main__":
    n = int(input().strip())
    health = 10.0

    experience = 0
    for i in range(n):
        a , b = map(float, input().strip().split())
        if health <= a:
            break
        if health-a > 10:
            health = 10.0
        else:
            health -= a
        experience += int(b)

    # 2^m 点经验可升一级
    level = 0
    while experience - (1 << level+1) >= 0:
        level += 1
        experience -= 1 << level
    

    if experience >= 1:
        experience -= 1
        level += 1
    print(level, experience)