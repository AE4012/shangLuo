import heapq

class Node:
    def __init__(self, weight, word=None, index=-1):
        self.weight = weight
        self.word = word
        self.index = index  # 记录原始输入顺序
        self.left = None
        self.right = None

    # 定义比较规则，供优先队列使用
    def __lt__(self, other):
        return self.weight < other.weight

def get_codes(node, current_code, codes):
    if node is None:
        return
    # 如果是叶子节点，记录编码
    if node.word:
        codes[node.index] = (node.word, current_code)
        return
    
    get_codes(node.left, current_code + "0", codes)
    get_codes(node.right, current_code + "1", codes)

def solve():
    try:
        n = int(input())
    except EOFError:
        return

    nodes = []
    # 存储原始数据以便最后按顺序输出
    original_data = []
    
    for i in range(n):
        line = input().split()
        s, w = line[0], int(line[1])
        new_node = Node(w, s, i)
        heapq.heappush(nodes, new_node)
        original_data.append(s)

    # 如果只有一个单词，特殊处理
    if n == 1:
        print(f"{original_data[0]} 0")
        return

    # 构建哈夫曼树
    while len(nodes) > 1:
        left = heapq.heappop(nodes)
        right = heapq.heappop(nodes)
        
        merged = Node(left.weight + right.weight)
        merged.left = left
        merged.right = right
        heapq.heappush(nodes, merged)

    # 递归获取编码
    root = nodes[0]
    result_codes = {}
    get_codes(root, "", result_codes)

    # 按原始顺序输出
    for i in range(n):
        word, code = result_codes[i]
        print(f"{word} {code}")

if __name__ == "__main__":
    solve()