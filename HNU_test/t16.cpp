#include<iostream>
#include<vector>

using namespace std;
int n, m;


int main(){
    cin >> n >> m;
    vector<pair<int,int>> A(n); 
    for(int i = 0; i < n; ++i){
        cin >> A[i].first >> A[i].second;
    }
    long long x, y;
    for(int i = 0; i < m; ++i){
        cin >> x >> y;
        for(int j = 0; j < n; ++j){
            x += A[j].first;
            y += A[j].second;
        }
        cout << x << ' ' << y << endl;
    }

    return 0;
}