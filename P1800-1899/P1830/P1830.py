
def solve():
    n, m, x, y = map(int, input().split())

    space = [[0] * (m+1) for _ in range(n+1)]
    last = [[0] * (m+1) for _ in range(n+1)]
    
    for i in range(1, x+1):
        x1, y1, x2, y2 = map(int, input().split())
        for r in range(x1, x2+1):
            for c in range(y1, y2+1):
                last[r][c] = i
                space[r][c] += 1
    for i in range(y):
        a, b = map(int, input().split())
        if space[a][b] == 0:
            print("N")
        else:
            print(f"Y {space[a][b]} {last[a][b]}")
        

if __name__ == "__main__":
    solve()