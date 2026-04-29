#include<iostream>

using namespace std;
int L, N;
int Positions;
int minT = 0, maxT = 0;

int main(){
    cin >> L >> N;
    for(int i = 0; i < N; ++i){
        cin >> Positions;
        minT = max(minT, min(Positions, L - Positions + 1));
        maxT = max(maxT, max(Positions, L - Positions + 1));
    }

    cout << minT << ' ' << maxT << endl;

    return 0;
}