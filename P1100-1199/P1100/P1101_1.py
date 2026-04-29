import sys

if __name__ == "__main__":
    n = int(input().strip())
    data = [list(input().strip()) for _ in range(n)]

    s = "yizhong"
    L = len(s)

    dirs = [(-1,-1), (-1,0), (-1,1),
        (0,-1),          (0,1),
        (1,-1),  (1,0),  (1,1)]

    keep = [[False]*n for _ in range(n)]

    for i in range(n):
        for j in range(n):
            if data[i][j] != 'y':  # 剪枝：必须是首字母
                continue

            # 判断边界
            for dx, dy in dirs:
                ok = True
                path = []
                # 先判断有没有越限
                for k in range(L):
                    x = i + dx*k
                    y = j + dy*k
                    if not (0 <= x < n and 0 <= y < n) or data[x][y] != s[k]:
                        ok = False
                        break
                    path.append((x, y))
            if ok:
                for x, y in path:
                    keep[x][y] = True

    ans = []
    for i in range(n):
        row = []
        for j in range(n):
            row.append(data[i][j] if keep[i][j] else '*')
        ans.append(''.join(row))

    print("\n".join(ans))