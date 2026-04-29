#include<iostream>

using namespace std;

#define MAX_N 20
#define ll long long
int n;

ll f[MAX_N][MAX_N];
ll dfs(int i, int j){
    //i为剩下几个待排的数，j为栈里的个数
    if(f[i][j]){
        return f[i][j];
    }
    if(i == 0){
        return 1;
    }
    if(j > 0){
        f[i][j] += dfs(i, j-1);
    }
    f[i][j] += dfs(i-1, j+1);
    return f[i][j];
}

int main(){
    cin >> n;
    cout << dfs(n, 0);


    return 0;
}