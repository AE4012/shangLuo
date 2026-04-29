"""
# P1109 学生分组

## 题目描述

有 $n$ 组学生，给出初始时每组中的学生个数，再给出每组学生人数的上界 $R$ 和下界 $L\ (L \le R)$，每次你可以在某组中选出一个学生把他安排到另外一组中，问最少要多少次才可以使 $N$ 组学生的人数都在 $[L,R]$ 中。

## 输入格式

第一行一个整数 $n$，表示学生组数；

第二行 $n$ 个整数，表示每组的学生个数；

第三行两个整数 $L,R$，表示下界和上界。

## 输出格式

一个数，表示最少的交换次数，如果不能满足题目条件输出 $-1$。

## 输入输出样例 #1

### 输入 #1

```
2
10 20
10 15

```

### 输出 #1

```
5
```

## 说明/提示

### 数据范围及约定

对于全部数据，保证 $1\le n \le 50$。
"""

import sys

def main():
    input = sys.stdin.readline
    n = int(input().strip())
    a = list(map(int, input().split())) # 每组学生个数
    L, R = map(int, input().split())    # 上界 下界

    S = sum(a)
    if S < n * L or S > n * R:
        print(-1)
        return

    """
    如果x < L：调整为L（最少不能少于L人）
    如果x > R：调整为R（最多不能多于R人）
    """
    b = [min(max(x, L), R) for x in a]
    base = sum(abs(ai - bi) for ai, bi in zip(a, b))
    delta = S - sum(b)

    ans = (base + abs(delta)) // 2
    print(ans)

if __name__ == "__main__":
    main()
