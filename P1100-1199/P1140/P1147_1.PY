import sys

def main():
    M = int(sys.stdin.readline().strip())

    l, r = 1, 2
    s = l + r

    # 至少两个数，所以 l 最大到 M//2
    while l <= M // 2:
        if s < M:
            r += 1
            s += r
        elif s > M:
            s -= l
            l += 1
            if l == r:  # 保证区间至少两个数
                r += 1
                s += r
        else:
            # s == M
            print(l, r)
            r += 1
            s += r

if __name__ == "__main__":
    main()
