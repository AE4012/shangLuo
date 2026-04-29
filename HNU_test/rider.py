if __name__ == "__main__":
    n, m, k = map(int, input().split())

    # 记录实心单元格，外围一圈全为实心单元格
    space = [[0] * (m + 2) for _ in range(n + 2)]
    for i in range(n + 2):
        space[i][0] = space[i][m + 1] = 1
    for j in range(m + 2):
        space[0][j] = space[n + 1][j] = 1

    # 实心单元
    for _ in range(k):
        x, y = map(int, input().split())
        space[x][y] = 1

    # 起点和方向
    xs, ys, s = input().split()
    xs, ys = int(xs), int(ys)

    # 方向编码
    dir_map = {"NE": 1, "SE": 2, "SW": 3, "NW": 4}
    tag = origin_tag = dir_map[s]

    # 存储经过的格子
    passby = set()
    passby.add((xs, ys))

    # 存储所有访问状态 (x, y, direction)
    visited_states = set()
    visited_states.add((xs, ys, tag))

    while True:
        # 移动逻辑
        if tag == 1:  # NE
            if space[xs-1][ys+1] and space[xs-1][ys] and space[xs][ys+1]:
                tag = 3
            elif space[xs-1][ys+1] and space[xs-1][ys]:
                tag = 2
                ys += 1
            elif space[xs-1][ys+1] and space[xs][ys+1]:
                tag = 4
                xs -= 1
            elif space[xs-1][ys+1]:
                tag = 3
            else:
                xs -= 1
                ys += 1

        elif tag == 4:  # NW
            if space[xs-1][ys-1] and space[xs-1][ys] and space[xs][ys-1]:
                tag = 2
            elif space[xs-1][ys-1] and space[xs-1][ys]:
                tag = 3
                ys -= 1
            elif space[xs-1][ys-1] and space[xs][ys-1]:
                tag = 1
                xs -= 1
            elif space[xs-1][ys-1]:
                tag = 2
            else:
                xs -= 1
                ys -= 1

        elif tag == 2:  # SE
            if space[xs+1][ys+1] and space[xs][ys+1] and space[xs+1][ys]:
                tag = 4
            elif space[xs][ys+1] and space[xs+1][ys+1]:
                tag = 3
                xs += 1
            elif space[xs+1][ys] and space[xs+1][ys+1]:
                tag = 1
                ys += 1
            elif space[xs+1][ys+1]:
                tag = 4
            else:
                xs += 1
                ys += 1

        else:  # SW
            if space[xs+1][ys-1] and space[xs][ys-1] and space[xs+1][ys]:
                tag = 1
            elif space[xs][ys-1] and space[xs+1][ys-1]:
                tag = 2
                xs += 1
            elif space[xs+1][ys] and space[xs+1][ys-1]:
                tag = 4
                ys -= 1
            elif space[xs+1][ys-1]:
                tag = 1
            else:
                xs += 1
                ys -= 1

        # 添加经过格子
        passby.add((xs, ys))

        # 检查状态是否重复
        state = (xs, ys, tag)
        if state in visited_states:
            break
        visited_states.add(state)

    # 输出经过的格子数
    print(len(passby))
