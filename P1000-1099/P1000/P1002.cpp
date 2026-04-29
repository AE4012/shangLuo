#include<iostream>

using namespace std;

int main(){
    int B_x, B_y, H_x, H_y;
    cin >> B_x >> B_y >> H_x >> H_y;
    B_x++; B_y++; H_x++; H_y++;

    long long chess[30][30] = {0};
    bool danger[30][30] = {false};

    long long attack[8][2] = {{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}};

    danger[H_x][H_y] = true;
    chess[1][0] = 1;

    for(int i = 0; i < 8; i++){
        int new_x = H_x + attack[i][0];
        int new_y = H_y + attack[i][1];
        if(new_x >= 1 && new_x <= B_x && new_y >= 1 && new_y <= B_y)
            danger[new_x][new_y] = true;
    }

    for(int x = 1; x <= B_x; x++){
        for(int y = 1; y <= B_y; y++){
            if(danger[x][y]) continue;
            chess[x][y] = chess[x-1][y] + chess[x][y-1];
        }
    }

    cout << chess[B_x][B_y] << endl;

    return 0;
}