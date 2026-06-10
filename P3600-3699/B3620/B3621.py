def generate_tuples():
    n, k = map(int, input().split())
    
    # 用于存储当前生成的元组
    current_tuple = []
    
    def dfs(depth):
        if depth == n:
            print(" ".join(map(str, current_tuple)))
            return
        
        # 核心逻辑：从 1 到 k 依次尝试填入当前位置
        # 因为是从 1 开始遍历到 k，自然保证了输出的字典序
        for i in range(1, k + 1):
            current_tuple.append(i)  # 做出选择
            dfs(depth + 1)           # 递归进入下一层
            current_tuple.pop()      # 回溯，撤销选择
            
    # 从第 0 层（第一个位置）开始搜索
    dfs(0)

if __name__ == "__main__":
    generate_tuples()