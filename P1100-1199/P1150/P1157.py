
import sys

if __name__ == "__main__":
    n, r = map(int, sys.stdin.readline().strip().split())
    comb = []

    def dfs(start, k):
        if k == 0:
            sys.stdout.write(''.join(f"{x:3d}" for x in comb) + '\n')
            return

        for i in range(start, n - k + 2):
            comb.append(i)
            dfs(i + 1, k - 1)
            comb.pop()

    dfs(1, r)



    