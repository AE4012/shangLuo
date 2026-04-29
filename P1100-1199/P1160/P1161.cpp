#include <iostream>
#include <cmath>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> lights_on;  // 用于记录开着的灯的编号
    
    for (int i = 0; i < n; ++i) {
        double a;
        int t;
        cin >> a >> t;
        
        for (int j = 1; j <= t; ++j) {
            int lamp = floor(j * a);
            
            // 如果灯编号已在集合中，表示按第二次应移除；否则加入集合。
            if (lights_on.count(lamp))
                lights_on.erase(lamp);
            else
                lights_on.insert(lamp);
        }
    }
    
    // 剩余的唯一开着的灯的编号
    cout << *lights_on.begin() << endl;
    
    return 0;
}
