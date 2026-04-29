#include<iostream>

using namespace std;
int n, L, r, t;
int A[605][605];
int temp[605][605];
int cnt = 0;

int main(){
    cin >> n >> L >> r >> t;

    int min_x, min_y;
    int max_x, max_y;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> A[i][j];
            temp[i][j] = 0;
        }
    
        for(int j = 0; j < n; ++j){
            if(j - r < 0){
                min_y = 0;
            }
            else{
                min_y = j - r;
            }
            if(j + r > n-1){
                max_y = n - 1;
            }
            else{
                max_y = j + r;
            }
            for(int y = min_y; y <= max_y; ++y){
                temp[i][j] += A[i][y];
            }
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){

            int sum = 0;
            int h = 0;
            if(i - r < 0){
                min_x = 0;
            }
            else{
                min_x = i - r;
            }
            if(i + r > n - 1){
                max_x = n - 1;
            }
            else{
                max_x = i + r;
            }

            if(j - r < 0){
                min_y = 0;
            }
            else{
                min_y = j - r;
            }
            if(j + r > n-1){
                max_y = n - 1;
            }
            else{
                max_y = j + r;
            }

            for(int x = min_x; x <= max_x; ++x){
                sum += temp[x][j];
            }

            h = (max_x - min_x + 1)*(max_y - min_y + 1);

            if(sum <= t*h)  cnt++;

        }
    }

    cout << cnt << endl;

    return 0;
}