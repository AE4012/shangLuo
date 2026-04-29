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

    # 字典序最小
    for i in range(1, n+1):
        adj[i].sort()

    visited = [False]*(n+1)

    stack = [1]
    visited[1] = True

    res = []

    while stack:
        u = stack.pop()
        res.append(str(u))

        for v in reversed(adj[u]):
            if not visited[v]:
                visited[v] = True
                stack.append(v)

    sys.stdout.write(" ".join(res))