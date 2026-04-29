#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 使用二分查找实现
int findLongestNonIncreasing(const vector<int>& missiles) {
    vector<int> ends; // 存储不升序列的末尾元素
    for (int height : missiles) {
        // 找到第一个 <= height 的位置
        // greater<int> 从大到小排好序的序列，找到第一个小于value的数
        auto it = upper_bound(ends.begin(), ends.end(), height, greater<int>()); 
        if (it == ends.end()) {
            ends.push_back(height);
        } else {
            *it = height;
        }
    }
    return ends.size();
}

int findLongestIncreasing(const vector<int>& missiles) {
    vector<int> ends; // 存储递增序列的末尾元素
    for (int height : missiles) {
        // 找到第一个 > height 的位置
        auto it = lower_bound(ends.begin(), ends.end(), height);
        if (it == ends.end()) {
            ends.push_back(height);
        } else {
            *it = height;
        }
    }
    return ends.size();
}

int main() {
    vector<int> missiles;
    int height;
    
    // 读取导弹高度
    while (cin >> height) {
        missiles.push_back(height);
    }
    
    // 第一问：最长不升序列
    int longestNonIncreasing = findLongestNonIncreasing(missiles);
    cout << longestNonIncreasing << endl;

    // 第二问：最长递增序列
    int longestIncreasing = findLongestIncreasing(missiles);
    cout << longestIncreasing << endl;

    return 0;
}
