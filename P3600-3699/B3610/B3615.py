"""
# B3615 测测你的矩阵乘法

## 题目描述

给定两个大小为均为 $512 \times 512$，每个元素均为整数，值域为 $ [0, 1024) $ 矩阵 $A, B$，定义为

$$ \begin{aligned}
	A\left[i, j\right] &= \left(\left(i \mathbin{\mathrm{or}} j\right) + j\right) \mathbin{\mathrm{xor}} \mathrm{seed}_A \\
    B\left[i, j \right] &= \left( \left(i \mathbin{\mathrm{and}} j \right) + i \right) \mathbin{\mathrm{xor}} \mathrm{seed}_B
\end{aligned} $$

其中 $i, j \in [0, 512)$。

请计算 $C = A \times B$。

## 输入格式

输入为两个整数 $\mathrm{seed}_A, \mathrm{seed}_B$（$0 \leq \mathrm{seed}_A, \mathrm{seed}_B < 1024$）。

你可以使用以下代码模板，完成其中的 `multiply` 即可。

你可以修改 $N$（即数组长度），但是不能修改 $n$（矩阵大小，恒为 $512$）。

```cpp
#include <bits/stdc++.h>
const int n = 512, N = n;
void multiply (int c[N][N], int a[N][N], int b[N][N]) {
	// c = a * b
}
int c[N][N], a[N][N], b[N][N];
int main() {
	int seedA, seedB;
	scanf("%d%d", &seedA, &seedB);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = ((i | j) + j) ^ seedA;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            b[i][j] = ((i & j) + i) ^ seedB;
    multiply(c, a, b);
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) sum ^= c[i][j];
        printf("%d\n", sum);
    }
}
```

## 输出格式

输出 $512$ 行，分别是 $C$ 每行的异或和。

输入中的代码会帮助你完成输出。

## 输入输出样例 #1

### 输入 #1

```
0 0
```

### 输出 #1

```
8126464
14942208
33554432
...(省略506行)
29097984
146800640
148570112
```
"""
n = 512
N = n
import sys

n = 512

def solve():
    # 使用快读提高输入效率
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    seed_A = int(input_data[0])
    seed_B = int(input_data[1])

    # 初始化矩阵
    a = [[((i | j) + j) ^ seed_A for j in range(n)] for i in range(n)]
    b = [[((i & j) + i) ^ seed_B for j in range(n)] for i in range(n)]
    
    # 结果矩阵 C 的每行异或和
    for i in range(n):
        row_xor_sum = 0
        for j in range(n):
            cij = 0
            # 这里的计算依然会非常慢，Python 建议采用更高效的方式
            for k in range(n):
                cij += a[i][k] * b[k][j]
            row_xor_sum ^= cij
        # 去掉多余的 print("\n")
        sys.stdout.write(str(row_xor_sum) + '\n')


if __name__ == "__main__":
    solve()