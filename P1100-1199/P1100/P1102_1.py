from collections import Counter

if __name__ == "__main__":
    N, C = map(int,input().split())
    data = list(map(int,input().split()))

    cnt = Counter(data)
    ans = 0
    for x, cx in cnt.items():
        ans += cx * cnt.get(x+C,0)

    print(ans)

