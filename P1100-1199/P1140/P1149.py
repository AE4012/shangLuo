

if __name__ == "__main__":
    stick_map = [6, 2, 5, 5, 4, 5, 6, 3, 7, 6]

    n = int(input().strip()) 

    cost = [0] * 2001
    for i in range(2001):
        if i == 0:
            cost[i] = stick_map[0]
        else:
            temp = i
            s = 0
            while temp > 0:
                s += stick_map[temp % 10]
                temp //= 10
            cost[i] = s

    count = 0
    # 减去加号和等号占用的 4 根
    target = n - 4
    
    # 双重循环枚举 A 和 B
    # 注意：如果 target 已经很小，可以进一步缩小 range 提高速度
    for a in range(1001):
        for b in range(1001):
            c = a + b
            if c <= 2000: # 确保索引不越界
                if cost[a] + cost[b] + cost[c] == target:
                    count += 1
                    
    print(count)