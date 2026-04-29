
import sys
from collections import deque

if __name__ == "__main__":
    n = int(sys.stdin.readline())
    data = []
    for _ in range(n):
        row = list(map(int, sys.stdin.readline().split()))
        data.append(row)
    
    vis = [[False] * n for _ in range(n)] # 标记是否访问过
    q = deque()

    # 把所有边界上的 0 入队（外部起点）
    for i in range(n):
        for j in (0, n - 1):
            if data[i][j] == 0 and not vis[i][j]:
                vis[i][j] = True
                q.append((i, j))
    for j in range(n):
        for i in (0, n - 1):
            if data[i][j] == 0 and not vis[i][j]:
                vis[i][j] = True
                q.append((i, j))

    dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)] # 方向向量
    while q:
        x, y = q.popleft()
        for dx, dy in dirs:
            nx, ny = x + dx, y + dy
            if 0 <= nx < n and 0 <= ny < n:
                if data[nx][ny] == 0 and not vis[nx][ny]:
                    vis[nx][ny] = True
                    q.append((nx, ny))

    for i in range(n):
        for j in range(n):
            if data[i][j] == 0 and not vis[i][j]:
                data[i][j] = 2

    for i in range(n):
        print(" ".join(map(str, data[i])))