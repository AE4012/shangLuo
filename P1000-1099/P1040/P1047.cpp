#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int l, m;
    cin >> l >> m;  // 读取马路长度和区域数量
    
    vector<pair<int, int>> intervals;  // 存储所有的区域 (u, v)
    
    // 读取所有区域
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        intervals.push_back({u, v});
    }
    
    // 按照起始点排序区域
    sort(intervals.begin(), intervals.end());
    
    // 合并重叠的区域
    vector<pair<int, int>> merged_intervals;
    
    for (auto& interval : intervals) {
        if (merged_intervals.empty() || merged_intervals.back().second < interval.first) {
            // 如果当前区域和最后一个合并区间不重叠，直接添加
            merged_intervals.push_back(interval);
        } else {
            // 如果重叠，合并区域
            merged_intervals.back().second = max(merged_intervals.back().second, interval.second);
        }
    }
    
    // 计算剩余树的数量
    int removed_trees = 0;
    for (auto& interval : merged_intervals) {
        removed_trees += (interval.second - interval.first + 1);
    }
    
    // 剩余树的数量
    int remaining_trees = (l + 1) - removed_trees;
    
    cout << remaining_trees << endl;  // 输出剩余树的数量
    return 0;
}
