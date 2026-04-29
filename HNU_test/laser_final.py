

if __name__ == "__main__":
    n, m, k = map(int, input().split())

    # 初始化空间，外围一圈为实心格
    space = [[0] * (m + 2) for _ in range(n + 2)]
    for i in range(n + 2):
        space[i][0] = space[i][m + 1] = 1
    for j in range(m + 2):
        space[0][j] = space[n + 1][j] = 1

    # 实心单元格
    for _ in range(k):
        x, y = map(int, input().split())
        space[x][y] = 1

    # 起点和方向
    xs, ys, s = input().split()
    xs, ys = int(xs), int(ys)

    # 方向向量
    dirs = {"NE": (-1, 1), "SE": (1, 1), "SW": (1, -1), "NW": (-1, -1)}
    dx, dy = dirs[s]

    # 用集合记录经过的格子
    passby = set()
    passby.add((xs, ys))

    # 用集合记录状态，防止无限循环
    visited_states = set()
    visited_states.add((xs, ys, dx, dy))

    while True:
        # 计算下一步
        nx, ny = xs + dx, ys + dy

        # 碰到实心格或边界，翻转对应方向
        if space[nx][ys]:
            dx *= -1
        if space[xs][ny]:
            dy *= -1

        # 移动
        xs += dx
        ys += dy

        passby.add((xs, ys))

        # 检查状态是否回到起点并且方向不变
        state = (xs, ys, dx, dy)
        if state in visited_states:
            break
        visited_states.add(state)

    # 输出经过格子数
    print(len(passby))
