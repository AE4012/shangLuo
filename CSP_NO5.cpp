#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#define ll long long

using namespace std;

int n, m;
int A[85][85];
ll dp[85][85];
ll result = 0;
ll p[85];

ll Cal_dp(int row, int start, int end){
    if(dp[start][end] != -1){
        return dp[start][end];
    }

    if(end - start >= 1){
        dp[start][end] = max(A[row][start] * p[m - (end - start)] + Cal_dp(row, start + 1, end),
            A[row][end] * p[m - (end - start)] + Cal_dp(row, start, end - 1));
    }
    else{
        dp[start][end] = A[row][start] * p[m - (end - start)];
    }
    return dp[start][end];
}

int main(){
    cin >> n >> m;

    p[0] = 1;
    for (int i = 1; i <= m; i++) {
        p[i] = p[i - 1] * 2;
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> A[i][j];
        }
        memset(dp, -1, sizeof(dp));

        result += Cal_dp(i, 1, m);
    }


    cout << result << endl;

    return 0;
}