
# P1033 [NOIP 2002 提高组] 自由落体
## 题目描述
"""在高为 $H$ 的天花板上有 $n$ 个小球，体积不计，位置分别为 $0,1,2,\cdots,n-1$。在地面上有一个小车（长为 $L$，高为 $K$，距原点距离为 $S_1$）。已知小球下落距离计算公式为 $d=0.5 \times g \times (t^2)$，其中 $g=10$，$t$ 为下落时间。地面上的小车以速度 $V$ 前进。

如下图：
![](https://cdn.luogu.com.cn/upload/image_hosting/1d177dhg.png)
小车与所有小球同时开始运动，当小球距小车的距离 $\le  0.0001$ (感谢 Silver_N 修正) 时，即认为小球被小车接受（小球落到地面后不能被接受）。
请你计算出小车能接受到多少个小球。
"""
## 输入格式
# $H,S_1,V,L,K,n$（$1 \le H,S_1,V,L,K,n \le 100000$）

## 输出格式
# 小车能接受到的小球个数。

## 输入输出样例 #1
### 输入 #1
"""
5.0 9.0 5.0 2.5 1.8 5
"""
### 输出 #1
"""
1
"""
## 说明/提示
"""当球落入车的尾部时，算作落入车内。
**【题目来源】**
NOIP 2002 提高组第三题
"""

import math

# 代码实现
def Count_caught(H, S1, V, L, K, n):
    # g=10 => 2/g = 0.2
    # sqrt(h/5) <=> sqrt(2h/g)
    t_max = math.sqrt(H / 5.0)  # 小球落地时间
    t_min = math.sqrt((H - K) / 5.0) if H > K else 0    # 小球落到车顶时间

    # 最早 + 最晚的小球编号
    first_ball = int(S1 + L - V*t_min)  # 车辆最右边的位置
    last_ball = int(S1 - V*t_max)       # 车辆最左边的位置

    
    # 计算落入车内的小球数量
    return max(0, min(n, first_ball) - max(0, last_ball)) 

if __name__ == "__main__":
    H, S1, V, L, K, n = map(float, input().split())
    n = int(n)

    print(Count_caught(H, S1, V, L, K, n))