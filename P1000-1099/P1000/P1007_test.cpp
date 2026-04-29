#include<iostream>
#include<algorithm>

using namespace std;
int minTime = 0, maxTime = 0;

int main(){
    int L, n;
    cin >> L >> n;
    int pos;
    for(int i = 0; i < n; ++i){
        cin >> pos;
        minTime = max(minTime, min(pos, L+1-pos));
        maxTime = max(maxTime, max(pos, L+1-pos));
    }
    cout << minTime << ' ' << maxTime << endl;



    return 0;
}