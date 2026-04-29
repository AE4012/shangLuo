#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int V, n;
int volumn[20005];
bool dp[20005] = {false};
int main(){
    cin >> V >> n;

    dp[0] = true;
    for(int i = 0; i < n; i++){
        cin >> volumn[i];
        for(int j = V; j >= volumn[i]; --j){
            if(dp[j-volumn[i]]){
                dp[j] = true;
            }
        }
    }

    for(int i = V; i >= 0; --i){
        if(dp[i]){
            cout << V-i << endl;
            return 0;
        }
    }

    return 0;
}