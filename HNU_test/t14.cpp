#include<iostream>
#include<vector>
#define ll long long

using namespace std;
int n, N;

int main(){
    cin >> n >> N;
    vector<int> A(n+2);
    A[0] = 0;
    A[n+1] = N;

    ll result = 0;
    for(int i = 1; i <= n; ++i){
        cin >> A[i];
    }

    for(int i = 1; i <= n; ++i){
        result += (A[i+1] - A[i])*i;
    }

    cout << result << endl;
    return 0;
}