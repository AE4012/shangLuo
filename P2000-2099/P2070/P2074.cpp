#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main(){
    int n, m, k, t;
    cin >> n >> m >> k >> t;

    int maxResult = -1;

    for(int i = 0; i < k; ++i){
        int x, y;
        cin >> x >> y;
    
        int count = 0;

        for(int dx = max(1, x - t); dx <= min(n,x + t); ++dx){
            for(int dy = max(1, y - t); dy <= min(m, y + t); ++dy){
                if(((dx-x)*(dx-x) + (dy-y)*(dy-y)) <= t*t)
                    count++;
            }    
        }

        maxResult = max(maxResult, count);
    }

    cout << maxResult << endl;

    return 0;
}