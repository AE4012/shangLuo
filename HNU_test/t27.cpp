#include<iostream>
#include<vector>

using namespace std;
int n, L, S;

int main(){
    cin >> n >> L >> S;
    vector<pair<int, int>> Trees(n+1);

    for(int i = 1; i <= n; ++i){
        cin >> Trees[i].first >> Trees[i].second;
    }

    vector<vector<int>> B(S+1, vector<int>(S+1));

    for(int i = S; i >= 0; --i){
        for(int j = 0; j <= S;++j)
            cin >> B[i][j];
    }
    
    vector<vector<int>> temp(S+1,vector<int>(S+1));
    int cnt = 0;

    for(int i = 1; i <= n; ++i){
        if(Trees[i].first > (L-S)||Trees[i].second > (L-S)){
            continue;
        }
        for(int x = S; x >= 0; x--){
            for(int y = 0; y <= S; ++y){
                temp[x][y] = 0;
            }
        }

        for(int k = 1; k <= n; ++k){
            int tempx = Trees[k].first - Trees[i].first;
            int tempy = Trees[k].second - Trees[i].second;
            if(tempx < 0 || tempx > S) continue;
            if(tempy < 0 || tempy > S) continue;
            temp[tempx][tempy] = 1;
        }

        int flag = 0;
        for(int x = S; x >= 0; x--){
            for(int y = 0; y <= S; ++y){
                if(temp[x][y] != B[x][y])   flag = 1;
            }
        }
        if(flag == 0)   cnt++;
    }

    cout << cnt << endl;
    return 0;
}