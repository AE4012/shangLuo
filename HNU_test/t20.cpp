#include<iostream>
#include<vector>

using namespace std;
int n, m;

int main(){
    cin >> n >> m;
    vector<vector<int>> CangKu(n, vector<int>(m));

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> CangKu[i][j];
        }
    }

    for(int i = 0; i < n; ++i){
        bool isFind = false;
        for(int j = 0; j < n; ++j){
            bool isUp = true;
            for(int k = 0; k < m; ++k){
                if(CangKu[j][k] <= CangKu[i][k]){
                    isUp = false;
                    break;
                }
            }
            if(isUp){
                cout << j+1 << endl;
                isFind = true;
                break;
            }
        }
        if(!isFind){
            cout << 0 << endl;
        }
    }


    return 0;
}