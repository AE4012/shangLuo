


if __name__ == "__main__":
    N = int(input().strip())
    data = [list(map(int, input().split())) for _ in range(N)]

    cover = [0] * 1000
    for start, end in data:
        for t in range(start, end):
            cover[t] += 1
    
    total = sum(1 for t in range(1000) if cover[t] > 0)

    ans = 0
    for start, end in data:
        individual = 0
        for t in range(start, end):
            if cover[t] == 1:
                individual += 1
        ans = max(ans, total - individual)

    print(ans)