#include<iostream>
#include<vector>
#define ll long long

using namespace std;

int n, m;

int main(){
    cin >> n >> m;
    vector<int> A(n+1);
    vector<int> B(n+1);
    vector<ll> C(n+1);

    C[0] = 1;

    for(int i = 1; i <= n; ++i){
        cin >> A[i];
        C[i] = A[i]*C[i-1];
        if(i == 1){
            cout << (m%C[i]) /C[i-1] << " ";
        }
        else{
            cout << (m%C[i] - m%C[i-1]) /C[i-1] << " "; 
        }
    }


    return 0;
}