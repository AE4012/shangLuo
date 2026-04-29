import sys

# 设置递归深度限制，防止 k=10 时溢出
sys.setrecursionlimit(2000000)

def solve():
    try:
        line1 = sys.stdin.readline()
        if not line1: return
        k = int(line1.strip())
        line2 = sys.stdin.readline()
        if not line2: return
        sx, sy = map(int, line2.split())
    except ValueError:
        return

    size = 1 << k
    # 初始化棋盘，坐标从 1 开始
    board = [[0] * (size + 1) for _ in range(size + 1)]
    
    # 全局计数器，用于标记 L 型骨牌编号
    tile_id = 0

    def tile_board(tr, tc, dr, dc, s):
        nonlocal tile_id
        if s == 1:
            return
        
        tile_id += 1
        current_id = tile_id
        half = s // 2
        
        # 1. 处理左上子棋盘
        if dr < tr + half and dc < tc + half:
            # 特殊方格在此区域
            tile_board(tr, tc, dr, dc, half)
        else:
            # 特殊方格不在，将右下角设为虚拟特殊点
            board[tr + half - 1][tc + half - 1] = current_id
            tile_board(tr, tc, tr + half - 1, tc + half - 1, half)
            
        # 2. 处理右上子棋盘
        if dr < tr + half and dc >= tc + half:
            tile_board(tr, tc + half, dr, dc, half)
        else:
            # 将左下角设为虚拟特殊点
            board[tr + half - 1][tc + half] = current_id
            tile_board(tr, tc + half, tr + half - 1, tc + half, half)
            
        # 3. 处理左下子棋盘
        if dr >= tr + half and dc < tc + half:
            tile_board(tr + half, tc, dr, dc, half)
        else:
            # 将右上角设为虚拟特殊点
            board[tr + half][tc + half - 1] = current_id
            tile_board(tr + half, tc, tr + half, tc + half - 1, half)
            
        # 4. 处理右下子棋盘
        if dr >= tr + half and dc >= tc + half:
            tile_board(tr + half, tc + half, dr, dc, half)
        else:
            # 将左上角设为虚拟特殊点
            board[tr + half][tc + half] = current_id
            tile_board(tr + half, tc + half, tr + half, tc + half, half)

    # 递归入口：(左上角行, 左上角列, 特殊点行, 特殊点列, 棋盘边长)
    tile_board(1, 1, sx, sy, size)
    
    # 打印结果
    for i in range(1, size + 1):
        print(*(board[i][1:]))

solve()