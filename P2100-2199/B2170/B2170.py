import sys
from collections import deque


if __name__ == "__main__":

    n = int(input().strip())
    data = sys.stdin.buffer.readlines()

    data = [list(map(int, line.strip().split())) for line in data]

    adj = [[] for _ in range(n+1)]
    for u, v in data:
        adj[u].append(v)
        adj[v].append(u)

    depth = [0]*(n+1)
    depth[1] = 1

    stack = deque([1])
    while stack:
        u = stack.popleft()
        for v in adj[u]:
            if depth[v] == 0:
                depth[v] = depth[u] + 1
                stack.append(v)

    print(" ".join(map(str, depth[1:])))
