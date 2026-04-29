"""
# P1105 平台

## 题目描述

空间中有一些平台。给出每个平台的位置，请你计算从每一个平台的边缘落下之后会落到哪一个平台上。

注意，如果某两个平台的某个两边缘横坐标相同，物体从上面那个平台落下之后将不会落在下面那个平台上（即平台的范围是一个开区间，不包含端点）。平台**可能会重叠**。

从平台下落时视作从平台下方开始下落，也就是说不会落到高度相同的平台上。**如果有两个平台的高度相同且都可以被落到的话，那么会落到编号靠前的那个平台。**

## 输入格式

第一行有一个数 $N$ 表示平台的个数;

接下来 $N$ 行每行三个整数 分别是平台的高度 $H_i$，左端点的 $X$ 坐标 $L_i$，右端点的 $X$ 坐标 $R_i$。

其中，$1 \le N \le {10}^3$，$0 \le H,L,R \le 2 \times {10}^4$。

## 输出格式

输出共 $N$ 行，每行两个数，分别表示：

从第 $i$ 个平台的左边缘落下后到达的平台序号和右边缘落下以后到达的平台序号。

输入数据中第一个平台的序号是 $1$。如果某个平台的某个边缘下面没有平台了，输出 $0$。

## 输入输出样例 #1

### 输入 #1

```
5
2 0 2
4 1 3
3 1 3
5 3 4
1 1 5

```

### 输出 #1

```
0 5
1 5
1 5
5 5
0 0

```

## 说明/提示

![](https://cdn.luogu.com.cn/upload/image_hosting/qeknowf7.png)
"""


import sys

def main():
    input = sys.stdin.readline
    N = int(input().strip())
    platforms = []
    for i in range(1, N + 1):
        h, l, r = map(int, input().split())
        platforms.append((h, l, r, i))

    # 高度升序；同高时编号升序（保证同高 tie-break 可控）
    platforms.sort(key=lambda x: (x[0], x[3]))

    ans = [None] * (N + 1)

    for j in range(N):
        hj, lj, rj, idxj = platforms[j]

        def find_below(x):
            best_h = -1
            best_idx = 0
            # 只看更低的平台：可以扫 0..j-1
            for k in range(j - 1, -1, -1):
                hk, lk, rk, idxk = platforms[k]
                if hk >= hj:   # 关键：严格更低
                    continue
                if not (lk < x < rk):  # 开区间
                    continue
                if hk > best_h:
                    best_h = hk
                    best_idx = idxk
                elif hk == best_h and idxk < best_idx:
                    best_idx = idxk
            return best_idx

        down_left = find_below(lj)
        down_right = find_below(rj)
        ans[idxj] = (down_left, down_right)

    for i in range(1, N + 1):
        print(ans[i][0], ans[i][1])

if __name__ == "__main__":
    main()


    

