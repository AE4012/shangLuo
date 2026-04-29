

if __name__ == "__main__":
    n = int(input().strip())
    life = 10.0
    exp = 0
    for _ in range(n):
        a, b = map(float, input().strip().split())
        if life <= a:
            break
        if life-a > 10:
            life = 10.0
        else:
            life -= a
        exp += int(b)

    level = 0
    while exp - (1 << level+1) >= 0:
        level += 1
        exp -= (1 << level)

    if exp >= 1:
        exp -= 1
        level += 1

    print(level, exp)
