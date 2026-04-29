import sys 

# Kruskal's Algorithm
def solve() -> int:
    input_data = sys.stdin.read().split()
    if not input_data:
        return
   
    n = int(input_data[0])
    m = int(input_data[1])
    
    edges = []
    ptr = 2
    # 循环 m 次读取所有边
    for _ in range(m):
        u = int(input_data[ptr])
        v = int(input_data[ptr+1])
        w = int(input_data[ptr+2])
        edges.append((u, v, w))
        ptr += 3

    edges.sort(key=lambda x: x[2]) # sort the edges by weight
    parent = [i for i in range(n+1)] # initialize the parent array

    def find_parent(i):
        if parent[i] == i:  # 初始状态
            return i
        parent[i] = find_parent(parent[i])
        return parent[i]


    def union(i, j):
        root_i = find_parent(i)
        root_j = find_parent(j)
        if root_i != root_j:
            parent[root_i] = root_j
            return True
        return False

    mst = 0 # initialize the minimum spanning tree
    edges_cnt = 0 # initialize the edges of the minimum spanning tree
    for u, v, w in edges:
        if union(u, v):
            mst += w
            edges_cnt += 1

            if edges_cnt == n - 1:
                break 
    return mst 

if __name__ == "__main__":
    print(solve())