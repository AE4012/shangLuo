#include<iostream>

using namespace std;
int n, k;
int ans = 0;

int dp[205][7];

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        dp[i][0] = 1;
        dp[i][1] = 1;
    }
    for(int j = 2; j <= k; ++j){
        dp[0][j] = 0;
        dp[1][j] = 0;
    }

    for(int i = 2; i <= n; ++i){
        for(int j = 2; j <= k; ++j){
            if(i > j)
                dp[i][j] = dp[i-1][j-1] + dp[i-j][j];
            else
                dp[i][j] = dp[i-1][j-1];
        }
    }

    cout << dp[n][k];


    return 0;
}