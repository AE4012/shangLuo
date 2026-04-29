#include<iostream>

using namespace std;

// Input data
int n, k;
// Output data
int ans = 0;

void dfs(int n, int k, int select){
    if(k == 1){
        ans++;
        return;
    }
    for(int i = select; i <= n/k; ++i){
        dfs(n - i, k - 1, i);
    }
}

int main(){
    cin >> n >> k;
    dfs(n, k, 1);
    cout << ans << endl;

    return 0;
}