


if __name__ == "__main__":
    N = int(input().strip())
    origin = [0]*N
    ans = [str(N)]

    for i in range(N):
        for j in range(N):
            if j != i:
                origin[j] ^= 1
        ans.append(''.join('1' if k else '0' for k in origin))
    

    for i in ans:
        print(i)


