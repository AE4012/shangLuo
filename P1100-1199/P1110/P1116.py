"""
冒泡排序步数
"""

import sys
8
def main():
    it = iter(sys.stdin.read().split())
    N = int(next(it))

    data = [int(next(it)) for _ in range(N)]

    step = 0
    for i in range(N):
        for j in range(N - 1 - i):
            if data[j] > data[j + 1]:
                data[j], data[j + 1] = data[j + 1], data[j]
                step += 1 # 每次交换步数加1

    print(step)

if __name__ == "__main__":
    main()

