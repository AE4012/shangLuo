import sys

def solve():
    N = int(sys.stdin.readline().strip())

    a = [0] * N  # 0 正面，1 反面
    out = [str(N)]

    # 第 i 次操作：不翻 i，其它全翻（i 从 0 到 N-1）
    for i in range(N):
        for j in range(N):
            if j != i:
                a[j] ^= 1
        out.append(''.join('1' if v else '0' for v in a))

    sys.stdout.write('\n'.join(out))

if __name__ == "__main__":
    solve()
