import sys

def solve():
    # 使用 sys.stdin.read().split() 一次性读取所有数据，速度最快
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    
    ptr = 0
    t = int(input_data[ptr])
    ptr += 1
    
    output = []
    
    for _ in range(t):
        n = int(input_data[ptr])
        m = int(input_data[ptr + 1])
        ptr += 2
        
        # 建立邻接表：使用列表嵌套列表
        adj = [[] for _ in range(n + 1)]
        
        # 读入边信息
        for _ in range(m):
            u = int(input_data[ptr])
            v = int(input_data[ptr + 1])
            ptr += 2
            adj[u].append(v)
            
        # 按照题目要求，从小到大排序并格式化输出
        for i in range(1, n + 1):
            if adj[i]:
                # 原地排序，效率最高
                adj[i].sort()
                # 使用 map 将数字转为字符串，再用空格拼接
                output.append(" ".join(map(str, adj[i])))
            else:
                # 无出边的节点输出空行
                output.append("")
                
    # 使用 sys.stdout.write 一次性输出，远快于多次 print
    sys.stdout.write("\n".join(output) + "\n")

if __name__ == '__main__':
    solve()