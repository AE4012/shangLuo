# P1058 - 立体图（基于标准 C++ 解法的 Python 复刻）
# 说明：
#  - 模板 block 的空格视为方块内部的空白，画图时要写入画布（不是透明）
#  - 偏移量：每一列向右偏移 4 列；每上一层向右偏移 2 列；每上一层向上偏移 3 行
#  - 绘制顺序：从后往前（行 m->1），每格从下到上（level 0 -> height-1），每行列从左到右

block = [
    "  +---+",
    " /   /|",
    "+---+ |",
    "|   | +",
    "|   |/ ",
    "+---+  "
]

def solve():
    import sys
    data = sys.stdin.read().strip().split()
    if not data:
        return
    it = iter(data)
    m = int(next(it)); n = int(next(it))
    a = []
    maxh = 0
    for _ in range(m):
        row = []
        for _ in range(n):
            v = int(next(it)); row.append(v)
            if v > maxh: maxh = v
        a.append(row)

        

if __name__ == "__main__":
    solve()
