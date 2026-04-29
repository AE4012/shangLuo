"""
# P1317 低洼地

## 题目描述

一组数，分别表示地平线的高度变化。高度值为整数，相邻高度用直线连接。找出并统计有多少个可能积水的低洼地？

如图：地高变化为 $[0,1,0,2,1,2,0,0,2,0]$。

![](https://cdn.luogu.com.cn/upload/image_hosting/c1zyz8wu.png)

## 输入格式

两行，第一行 $n,$ 表示有 $n$ 个数。第 $2$ 行连续 $n$ 个数表示地平线高度变化的数据，保证首尾为 $0$。$(3 \le n \le 10000,0 \le $ 高度 $ \le 1000)$。

## 输出格式

一个数，可能积水低洼地的数目。

## 输入输出样例 #1

### 输入 #1

```
10
0 1 0 2 1 2 0 0 2 0
```

### 输出 #1

```
3
```
"""
if __name__ == "__main__":
    n = int(input())
    level = list(map(int, input().split()))

    ans = 0
    i = 0

    left = False
    right = False
    
    while i < n-1:
        if level[i] > level[i+1]:
            left = True
            down = i+1
            while down < n-1 and level[down] >= level[down+1]:
                down += 1
            
            up = down

            while up < n-1 and level[up+1] > level[up]:
                right = True
                up += 1

            if left and right:
                ans += 1
                left = False
                right = False
            i = up

        else:
            i += 1

    print(ans)       


            
        
        


