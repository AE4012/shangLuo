#include<iostream>

using namespace std;
int n, k;
int ans = 0;

void dfs(int a, int n, int k){
    if(k == 1){
        ans++;
        return;
    }
    for(int i = a; i <= n/k; ++i){
        dfs(i, n-i, k-1);
    }
}

int main(){
    cin >> n >> k;
    dfs(1, n, k);

    cout << ans << endl;
    return 0;
}