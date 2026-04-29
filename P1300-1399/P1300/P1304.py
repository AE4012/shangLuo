"""
P1300-1399.P1300.P1304 的 Docstring

# P1304 哥德巴赫猜想

## 题目描述

输入一个偶数 $N$，验证 $4\sim N$ 所有偶数是否符合哥德巴赫猜想：任一大于 $2$ 的偶数都可写成两个质数之和。如果一个数不止一种分法，则输出第一个加数相比其他分法最小的方案。例如 $10$，$10=3+7=5+5$，则 $10=5+5$ 是错误答案。

## 输入格式

第一行输入一个正偶数 $N$

## 输出格式

输出 $\dfrac{N-2}{2}$ 行。对于第 $i$ 行：

首先先输出正偶数 $2i+2$，然后输出等号，再输出加和为 $2i+2$ 且第一个加数最小的两个质数，以加号隔开。

## 输入输出样例 #1

### 输入 #1

```
10
```

### 输出 #1

```
4=2+2
6=3+3
8=3+5
10=3+7
```

## 说明/提示

数据保证，$ 4 \leq N\leq10000$。

"""

if __name__ == "__main__":
    N = int(input())
    # 生成质数表
    is_prime = [True]*(N+1)
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(pow(N, 0.5)) + 1):
        if is_prime[i]:
            for j in range(i*i, N+1, i):
                # 标记非质数,i*i,i*(i+1),...
                is_prime[j] = False
    for even in range(4, N+1, 2):
        # even所有大于2的偶数
        for first in range(2, even):
            if is_prime[first] and is_prime[even - first]:
                print(f"{even}={first}+{even - first}")
                break