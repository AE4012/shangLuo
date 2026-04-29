#include<iostream>

using namespace std;
int n, m, p, q;
int A[10005];

int main(){
    cin >> n >> m >> p >> q;
    for(int i = 0; i < n*m; ++i){
        cin >> A[i];
    }

    int k = 0;
    for(int i = 0; i < p; ++i){
        for(int j = 0; j < q; ++j){
            if(j == q-1){
                cout << A[k];
            }
            else{
                cout << A[k] << " ";
            }
            k++;
        }
        cout << endl;
    }


    return 0;
}