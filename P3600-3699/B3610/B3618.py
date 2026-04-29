import sys

def success():
    data = sys.stdin.readline().split()

    n, k = map(int, data)

    basis = [0]*64

    def insert(x):
        for i in range(k-1, -1, -1):
            # 如果当前位为 0，则跳过
            if not (x >> i) & 1:
                continue
            if not basis[i]:
                basis[i] = x
                break
            x ^= basis[i]  


    for _ in range(n):
        human = list(map(int, sys.stdin.readline().split()))
        if not human:
            continue
        custom = human[0]
        abilities = human[1:]

        val = 0 
        for a in abilities:
            val |= (1 << (k-a))

        insert(val)

    ans = 0
    for i in range(k-1, -1, -1):
        if (ans ^ basis[i]) > ans:
            ans ^= basis[i]

    print(ans)
    pass


if __name__ == "__main__":
    success()
