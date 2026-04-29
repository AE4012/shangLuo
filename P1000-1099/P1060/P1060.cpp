#include<bits/stdc++.h>
#include<vector>

//01背包问题
using namespace std;

//input output
int n, m;
int dp1[25][30000];  //dp[i][j]表示前i个物品，容量为j的背包所能装的最大价值————无优化
int dp2[30000];     //dp[i]表示容量为i的背包所能装的最大价值————一维数组优化

struct Node{
    int v, p;
    // node(int _w, int _v):w(_w), v(_v){}
}node[30];

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; ++i){
        int a, b;
        cin >> node[i].v >> node[i].p;
        node[i].p *= node[i].v;
    }

    // 物品数量为m，背包容量为n
    for(int i = 1; i <= m; ++i){
        for(int j = 0; j <= n; ++j){
            dp1[i][j] = dp1[i-1][j];
            if(j > node[i].v){
                dp1[i][j] = max(dp1[i][j], dp1[i-1][j-node[i].v] + node[i].p);
            }
        }
    }

    // for(int i =  1; i <= m; ++i){
    //     for(int j = n; j >= node[i].v; --j){
    //         dp2[j] = max(dp2[j], dp2[j-node[i].v] + node[i].p);
    //     }
    // }

    cout << dp1[m][n] << endl;
    // cout << dp2[n] << endl;

    return 0;
}