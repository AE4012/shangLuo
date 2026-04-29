#include<iostream>

using namespace std;

int n;
int dp[1005] = {0};
int main(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= i/2; ++j){
            dp[i] += dp[j];
        }
        dp[i] += 1;
    }

    cout << dp[n] << endl;

    return 0;
}