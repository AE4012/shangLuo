#include<iostream>

using namespace std;

int n;
int dp[20][20];

int main(){
    cin >> n;

    for(int i = 0; i <= n; ++i){
        dp[i][0] = 1;
    }

    //遍历所有输入
    for(int j = 1; j <= n; ++j){
        for(int i = 0; i <= n; ++i){
            //栈有i个数字,可以j-1, i+1入栈
            //直接输出i-1
            if(i >= 1){
                dp[i][j] += dp[i-1][j] + dp[i+1][j-1];
            }
            //栈空只能进
            if(i == 0){
                dp[i][j] = dp[i+1][j-1];
            }
        }
    }
    cout << dp[0][n] << endl;

    return 0;
}