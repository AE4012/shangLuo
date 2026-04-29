"""
P1400-1499.P1420.P1420 的 Docstring
# P1420 最长连号

## 题目描述

输入长度为 $n$ 的一个正整数序列，要求输出序列中最长连号的长度。

连号指在序列中，从小到大的连续自然数。

## 输入格式

第一行，一个整数 $n$。

第二行，$n$ 个整数 $a_i$，之间用空格隔开。

## 输出格式

一个数，最长连号的长度。

## 输入输出样例 #1

### 输入 #1

```
10
1 5 6 2 3 4 5 6 8 9
```

### 输出 #1

```
5
```

## 说明/提示

#### 数据规模与约定

对于 $100\%$ 的数据，保证 $1 \leq n \leq 10^4$，$1 \leq a_i \leq 10^9$。
"""

if __name__ == "__main__":
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    
    max_length = 1
    current_length = 1
    for i in range(1, n):
        if arr[i] == arr[i-1]+1:
            current_length += 1
        else:
            max_length = max(max_length, current_length)
            current_length = 1
    max_length = max(max_length, current_length)

    print(max_length)