

if __name__ == "__main__":
    n = int(input().strip())
    data = list(map(int, input().strip().split()))

    data.sort()
    max_floor = data[-1]
    total = 10*max_floor

    i = 0
    while i < n:
        j = i + 1
        """
        统计 data[i] 出现的次数
        """
        while j < n and data[j] == data[i]:
            j += 1
        cnt = j - i
        total += 5 + cnt
        i = j


    print(total)
