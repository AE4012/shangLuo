#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    if(n == 1){
        cout << "Jolly" << endl;
        return 0;
    }

    set<int> data;
    long value, value_old;
    cin >> value_old;

    for(int i = 1; i < n; i++){
        cin >> value;
        int diff = abs(value - value_old);

        // 检查差值范围是否在 [1, n-1]
        if(diff < 1 || diff >= n) {
            cout << "Not jolly" << endl;
            return 0;
        }

        data.insert(diff);
        value_old = value;
    }

    if(data.size() != n-1){
        cout << "Not jolly" << endl;
    }
    else{
        cout << "Jolly" << endl;
    }

    

    return 0;
}
