#include<iostream>
#include<vector>
#define pi 3.1415926535

using namespace std;


int main(){
    int N;
    cin >> N;

    vector<pair<int, int>> heizi(N);

    int x, y;
    for(int i = 0; i < N; ++i){
        cin >> heizi[i].first >> heizi[i].second;
    }
    double mianji;

    long banjin;
    long min_banjin = 2*10000*10000;
    for(int i = 0; i < N; i++){
        int ox = heizi[i].first, oy = heizi[i].second;
        long max_banjin = -1;
        for(int j = 0; j < N; ++j){
            banjin = (heizi[j].first - ox)*(heizi[j].first - ox) + (heizi[j].second - oy)*(heizi[j].second - oy);
            max_banjin = max(banjin, max_banjin);
        }
        min_banjin = min(max_banjin, min_banjin);
    }

    mianji = pi * min_banjin;
    printf("%.4f", mianji);


    return 0;
}