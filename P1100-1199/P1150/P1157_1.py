


import sys


if __name__ == "__main__":
    n, r = map(int, input().strip().split())
    
    combine = []
    
    def dfs(start: int, k:int):
        if k == 0:
            sys.stdout.write(''.join(f"{x:3d}" for x in combine) + '\n')
            return
        

        for i in range(start, n - k + 2):
            combine.append(i)

            dfs(i+1, k-1)
            combine.pop()


    dfs(1, r)
            

