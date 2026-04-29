#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    unordered_set<int> numSet;      // 存储输入的数，方便查找
    unordered_set<int> valid_sums;  // 存储已找到的符合条件的和，防止重复

    // 读入数字并存入集合
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        numSet.insert(nums[i]);
    }

    int count = 0;

    // 对所有不同的数对进行检查
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int sum = nums[i] + nums[j];
            // 检查和是否在集合中，并且没有重复计数
            if (numSet.find(sum) != numSet.end() && valid_sums.find(sum) == valid_sums.end()) {
                count++;
                valid_sums.insert(sum);  // 记录该和，防止重复
            }
        }
    }

    cout << count << endl;

    return 0;
}
