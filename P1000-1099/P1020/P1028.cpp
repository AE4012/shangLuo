#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

/*
# [NOIP2001 普及组] 数的计算

## 题目描述

给出正整数 $n$，要求按如下方式构造数列：

1. 只有一个数 $n$ 的数列是一个合法的数列。
2. 在一个合法的数列的末尾加入一个正整数，但是这个正整数不能超过该数列最后一项的一半，可以得到一个新的合法数列。

请你求出，一共有多少个合法的数列。两个合法数列 $a, b$ 不同当且仅当两数列长度不同或存在一个正整数 $i \leq |a|$，使得 $a_i \neq b_i$。
*/

int main(){
    int n;
    cin >> n;

    vector<int> dp(n+1, 0);
    dp[n] = 1;

    for(int x = n; x > 0; x--){
        for(int y = 1; y <= x/2; y++){
            dp[y] += dp[x];
        }
    }

    int result = 0;
    for(int i = 1; i <= n; i++){
        result += dp[i];
    }
    cout << result << endl;

    return 0;
}