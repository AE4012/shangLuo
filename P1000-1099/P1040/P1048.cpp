#include<iostream> 
#include<algorithm>

using namespace std;

int T, M;
int t, value;
int dp[1005] = {0};

int main(){
    cin >> T >> M;
    for(int i = 0; i < M; ++i){
        cin >> t >> value;
        for(int j = T; j >= t; --j){
            dp[j] = max(dp[j], dp[j-t] + value);
        }
    }

    cout << dp[T] << endl;

    return 0;
}