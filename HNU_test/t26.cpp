#include<iostream>
#include<vector>
#include<climits>

using namespace std;
int n, x;

int main(){
    cin >> n >> x;
    int sum = 0; 
    vector<int> Prices(n);
    for(int i = 0; i < n; ++i){
        cin >> Prices[i];
        sum += Prices[i];
    }

    vector<int> dp(sum + 1, INT_MAX);
    dp[0] = 0;

    for(int i = 0; i < n; ++i){
        for(int j = sum; j >= Prices[i]; --j){
            if(dp[j-Prices[i]] != INT_MAX){
                dp[j] = dp[j-Prices[i]]+Prices[i];
            }
        }
    }

    int result = INT_MAX;
    for(int i = x; i <= sum; ++i){
        if(dp[i] != INT_MAX){
            cout << dp[i] << endl;
            return 0;

        }
    }

    // cout << result << endl;

    return 0;
}