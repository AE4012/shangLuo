import sys
from collections import deque

if __name__ == "__main__":
    data = sys.stdin.readlines()

    n = int(data[0].strip())

    graph = [[] for _ in range(n+1)]

    for i in range(n - 1):
        u,v = map(int,data[i+1].strip().split())
        graph[u].append(v)
        graph[v].append(u)



    for i in range(1,n+1):
        graph[i].sort()

    visited = [False] *(n+1)

    queue = deque()
    queue.append(1)
    visited[1] = True

    ans = []

    while queue:
        node = queue.popleft()
        ans.append(node)
       
        for next_node in graph[node]:
            if not visited[next_node]:
                visited[next_node] = True
                queue.append(next_node)


    print(*ans)