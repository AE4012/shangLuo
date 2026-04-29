import sys

if __name__ == "__main__":
    data = list(map(int, sys.stdin.buffer.read().split()))
    n = data[0]

    adj = [[] for _ in range(n+1)]

    idx = 1
    for _ in range(n-1):
        u = data[idx]
        v = data[idx+1]
        idx += 2
        adj[u].append(v)
        adj[v].append(u)


    order = []

    parent = [0]*(n+1)
    queue = [1]
    parent[1] = -1  #已访问

    head = 0
    while head < len(queue):
        u = queue[head]
        head += 1
        order.append(u)
        for v in adj[u]:
            if parent[v] == 0:
                parent[v] = u
                queue.append(v)

    # 逆序计算子树大小
    subtree_size = [1] * (n + 1)
    # 从后往前遍历，保证处理父节点时，子节点已经计算完毕
    for i in range(n - 1, 0, -1):
        u = order[i]
        p = parent[u]
        if p != -1:
            subtree_size[p] += subtree_size[u]
    sys.stdout.write(" ".join(map(str, subtree_size[1:])) + "\n")