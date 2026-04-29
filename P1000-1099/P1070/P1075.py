"""
P1075.py
求最大素因子
# P1075 [NOIP 2012 普及组] 质因数分解

## 题目描述

已知正整数 $n$ 是两个不同的质数的乘积，试求出两者中较大的那个质数。

## 输入格式

输入一个正整数 $n$。

## 输出格式

输出一个正整数 $p$，即较大的那个质数。

## 输入输出样例 #1

### 输入 #1

```
21
```

### 输出 #1

```
7
```

## 说明/提示

$1 \le n\le 2\times 10^9$

NOIP 2012 普及组 第一题
"""


from math import sqrt
def Cal_primes(n):   
    """
    Cal_primes 的 Docstring
    计算构成 n 的素数乘积
    :param n: 正整数
    :return: 素数乘积列表
    """
    primes = []
    # 处理 2 的倍数
    while n % 2 == 0:
        primes.append(2)
        n //= 2

    # 处理奇数因子
    for i in range(3, int(sqrt(n)) + 1, 2):
        while n % i == 0:
            primes.append(i)
            n //= i

    # 如果 n 是一个大于 2 的素数
    if n > 2:
        primes.append(n)

    return primes


if __name__ == "__main__":
    n = int(input())
    primes = Cal_primes(n)
    print(max(primes))