#include<iostream>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int total_smokes = n;  // 初始吸的烟数量
    int remaining_butt = n;  // 初始的烟蒂数量
    
    while (remaining_butt >= k) {
        int new_smokes = remaining_butt / k;  // 可以换的新烟数量
        total_smokes += new_smokes;  // 新烟数量加到总数
        remaining_butt = remaining_butt % k + new_smokes;  // 更新剩余烟蒂
    }
    
    cout << total_smokes << endl;


    return 0;
}