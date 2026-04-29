#include<iostream>
#include<vector>

using namespace std;

int main(){
    int N, M, B, G;
    cin >> N >> M >> B >> G;

    int x, y;
    int line_B = 0, row_G = 0;
    long long result = 0;

    vector<bool> selectB(N+1, false);
    for(int i = 1; i <= B; ++i){
        cin >> x >> y;

        for(int j = x; j <= y; ++j){
            if(!selectB[j]){
                selectB[j] = true;
                line_B++;
            }   
        }
    }

    vector<bool> selectG(M+1, false);
    for(int i = 1; i <= G; ++i){
        cin >> x >> y;

        for(int j = x; j <= y; ++j){
            if(!selectG[j]){
                selectG[j] = true;
                row_G++;
            }   
        }
    }

    result += line_B*M + row_G*N - line_B*row_G;

    cout << result << endl;

    return 0;
}