#include<iostream>
#include<vector>

using namespace std;
long long V[10001][21];
int Q[10001][21];
int KT[21][10001];
int W[10001];
long long temp[21][21];
int n, d;

int main(){
    cin >> n >> d;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < d; ++j){
            cin >> Q[i][j];
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < d; ++j){
            cin >> KT[j][i];
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < d; ++j){
            cin >> V[i][j];
        }
    }

    for(int i = 0; i < n; ++i){
        cin >> W[i];
    }

    for(int i = 0; i < d; ++i){
        for(int j = 0; j < d; ++j){
            for(int k = 0; k < n; ++k){
                temp[i][j] += KT[i][k]*V[k][j];
            }
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < d; ++j){
            V[i][j] = 0;
            for(int k = 0; k < d; ++k){
                V[i][j] += Q[i][k]*temp[k][j];
            }
            V[i][j] *= W[i];
            cout << V[i][j] << " ";
        }
        cout << endl;
    }
    


    return 0;
}