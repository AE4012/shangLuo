import sys
from collections import deque

if __name__ == "__main__":
    input = sys.stdin.readline

    n = int(input())

    # 建立邻接表
    graph = [[] for _ in range(n + 1)]

    for _ in range(n - 1):
        u, v = map(int, input().split())
        graph[u].append(v)
        graph[v].append(u)

    # 排序保证先访问编号小的节点
    for i in range(1, n + 1):
        graph[i].sort()

    visited = [False] * (n + 1)

    queue = deque()
    queue.append(1)
    visited[1] = True

    result = []

    while queue:
        node = queue.popleft()
        result.append(node)

        for next_node in graph[node]:
            if not visited[next_node]:
                visited[next_node] = True
                queue.append(next_node)

    print(*result)