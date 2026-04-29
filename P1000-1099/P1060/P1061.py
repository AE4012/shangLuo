"""
# P1061 [NOIP 2006 普及组] Jam 的计数法

## 题目描述

Jam 是个喜欢标新立异的科学怪人。他不使用阿拉伯数字计数，而是使用小写英文字母计数，他觉得这样做，会使世界更加丰富多彩。

在他的计数法中，每个数字的位数都是相同的（使用相同个数的字母），英文字母按原先的顺序，排在前面的字母小于排在它后面的字母。我们把这样的“数字”称为 Jam 数字。在 Jam 数字中，每个字母互不相同，而且从左到右是严格递增的。每次，Jam 还指定使用字母的范围，例如，从 $2\sim 10$，表示只能使用 ${b,c,d,e,f,g,h,i,j}$ 这些字母。如果再规定位数为 $5$，那么，紧接在 Jam 数字 $\texttt{bdfij}$ 之后的数字应该是 $\texttt{bdghi}$。（如果我们用 $U$、$V$ 依次表示 Jam 数字 $\texttt{bdfij}$ 与 $\texttt{bdghi}$，则 $U<V$，且不存在 Jam 数字 $P$，使 $U<P<V$）。

你的任务是：对于从文件读入的一个 Jam 数字，按顺序输出紧接在后面的 $5$ 个 Jam 数字，如果后面没有那么多 Jam 数字，那么有几个就输出几个。

## 输入格式

共 $2$ 行。

第 $1$ 行为 $3$ 个正整数 $s, t, w$，用一个空格隔开。

（其中 $s$ 为所使用的最小的字母的序号，$t$ 为所使用的最大的字母的序号。$w$ 为数字的位数，这 $3$ 个数满足：$1\le s<t\le 26,2\le w\le t-s$）

第 $2$ 行为具有 $w$ 个小写字母的字符串，为一个符合要求的 Jam 数字。

所给的数据都是正确的，不必验证。

## 输出格式

最多为 $5$ 行，为紧接在输入的 Jam 数字后面的 $5$ 个 Jam 数字，如果后面没有那么多 Jam 数字，那么有几个就输出几个。每行只输出一个 Jam 数字，是由 $w$ 个小写字母组成的字符串，不要有多余的空格。

## 输入输出样例 #1

### 输入 #1

```
2 10 5
bdfij
```

### 输出 #1

```
bdghi
bdghj
bdgij
bdhij
befgh
```

## 说明/提示

NOIP 2006 普及组 第三题
"""


if __name__ == "__main__":
    s, t, w = map(int, input().split())
    jam_str = list(input().strip())

    jam_num = [ord(c) - ord('a') + 1 for c in jam_str]

    limit = [t - w + i + 1 for i in range(w)]  # 每一位的最大值
    # print(limit)

    def next_jam(arr):
        """生成下一个 Jam 数字"""
        """ 数字和字符串的转换：
            str -> num : ord(c)
            num -> str : chr(n)
        """ 
        arr = arr[:]
        # 从后往前找到第一个可以增加的字符位置 
        for i in range(w - 1, -1, -1):
            if arr[i] < limit[i]:
                arr[i] += 1
                # 将后面的字符依次设置为递增的最小值
                for j in range(i + 1, w):
                    arr[j] = arr[j - 1] + 1
                return arr
        return None
    
    cnt = 0
    while cnt < 5:
        jam_num = next_jam(jam_num)
        if jam_num is None:
            break
        jam_str = ''.join(chr(c + ord('a') - 1) for c in jam_num)
        print(jam_str)
        cnt += 1





