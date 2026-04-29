

import sys

def main():
    input = sys.stdin.readline
    n = int(input().strip())
    grid = [list(input().strip()) for _ in range(n)]
    
    s = "yizhong"
    L = len(s)

    dirs = [(-1,-1), (-1,0), (-1,1),
            (0,-1),          (0,1),
            (1,-1),  (1,0),  (1,1)]

    keep = [[False]*n for _ in range(n)]

    for i in range(n):
        for j in range(n):
            if grid[i][j] != 'y':  # 剪枝：必须是首字母
                continue

            for dx, dy in dirs:
                ok = True
                path = []
                # 先判断有没有越限
                for k in range(L):
                    x = i + dx*k
                    y = j + dy*k
                    if not (0 <= x < n and 0 <= y < n) or grid[x][y] != s[k]:
                        ok = False
                        break
                    path.append((x, y))

                if ok:
                    for x, y in path:
                        keep[x][y] = True

    out_lines = []
    for i in range(n):
        row = []
        for j in range(n):
            row.append(grid[i][j] if keep[i][j] else '*')
        out_lines.append(''.join(row))

    print("\n".join(out_lines))

if __name__ == "__main__":
    main()
