"""
# P1037 [NOIP 2002 普及组] 产生数

## 题目描述

给出一个整数 $n$ 和 $k$ 个变换规则。

规则：
- 一位数可变换成另一个一位数。
- 规则的右部不能为零。

例如：$n=234,k=2$。有以下两个规则：

- $2\longrightarrow 5$。  
- $3\longrightarrow 6$。 

上面的整数 $234$ 经过变换后可能产生出的整数为（包括原数）:

- $234$。
- $534$。
- $264$。
- $564$。

共 $4$ 种不同的产生数。

现在给出一个整数 $n$ 和 $k$ 个规则。求出经过任意次的变换（$0$ 次或多次），能产生出多少个不同整数。

仅要求输出个数。

## 输入格式

第一行两个整数 $n,k$，含义如题面所示。

接下来 $k$ 行，每行两个整数 $x_i,y_i$，表示每条规则。

## 输出格式

共一行，输出能生成的数字个数。

## 输入输出样例 #1

### 输入 #1

```
234 2
2 5
3 6
```

### 输出 #1

```
4
```

## 说明/提示

对于 $100\%$ 数据，满足 $n \lt 10^{30}$，$k \le 15$。

**【题目来源】**

NOIP 2002 普及组第三题
"""

def rules2num():
    n_str, k = input().strip().split()
    k = int(k)
    # 初始化转换规则
    rules = [[False] for _ in range(10)]    # 0~9的数字
    for i in range(10):
        rules[i] = [False] * 10  # 初始化为不可转换
        rules[i][i] = True    # 自身可转换

    for _ in range(k):
        x, y = map(int, input().strip().split())
        rules[x][y] = True # 从 x 可转换到 y

    # 传递闭包
    for m in range(10):     
        for i in range(10):
            if rules[i][m]:
                for j in range(10):
                    if rules[m][j]:
                        rules[i][j] = True
    
    # 计算每一位可转换的数字集合
    digit_options = [0] * 10
    for i in range(10):
        for j in range(10):
            if rules[i][j]:
                digit_options[i] += 1

    # 计算总的不同数字个数
    total_count = 1
    for ch in n_str:
        digit = int(ch)
        total_count *= digit_options[digit]
    return total_count

if __name__ == "__main__":

    print(rules2num())