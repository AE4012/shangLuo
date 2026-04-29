"""
P1400-1499.P1420.P1424 的 Docstring
# P1424 小鱼的航程（改进版）

## 题目描述

有一只小鱼，它平日每天游泳 $250$ 公里，周末休息（实行双休日)，假设从周 $x$ 开始算起，过了 $n$ 天以后，小鱼一共累计游泳了多少公里呢？

## 输入格式

输入两个正整数 $x,n$，表示从周 $x$ 算起，经过 $n$ 天。

## 输出格式

输出一个整数，表示小鱼累计游泳了多少公里。

## 输入输出样例 #1

### 输入 #1

```
3 10
```

### 输出 #1

```
2000
```

## 说明/提示

数据保证，$1\le x \le 7$，$1 \le n\le 10^6$。
"""

if __name__ == "__main__":
    x, n = map(int, input().strip().split())
    day = 0
    week = n//7
    day += 5*week
    # print(day)
    rest = n % 7
    # print(rest)
    if x == 7:
        day += max(0, rest - 1)
    elif x == 6:
        day += max(0, rest - 2)
    else:
        if rest + x == 7:
            day += rest - 1
        elif rest + x > 7:
            day += rest - 2
        else:
            day += rest


    print(int(day * 250))