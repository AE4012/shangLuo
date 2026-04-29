#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int N = 30;
int used[N]; // 记录单词使用次数
string t[N]; // 存储单词
string startWord; // 起始单词
int n, maxx = 0;

// 计算两个单词的重叠部分长度
int calcOverlap(string pre, string next) {
    for (int i = pre.size() - 1; i >= 0; --i) {
        if (pre[i] == next[0]) {
            int tag = i;
            for (int j = 0; j < next.size(); ++j) {
                if (pre[tag] == next[j]) tag++;
                else break;
            }
            if (tag == pre.size()) return tag - i;
        }
    }
    return 0;
}

// 深度优先搜索 + 回溯
void dfs(int overlapSum, string current) {
    maxx = max(maxx, (int)current.size() - overlapSum);

    for (int i = 1; i <= n; ++i) {
        int overlapLen = 0;
        if (used[i] == 2) continue; // 单词使用次数限制
        overlapLen = calcOverlap(current, t[i]);
        if (overlapLen == 0) continue; // 无重叠部分则跳过

        used[i]++;
        dfs(overlapSum + overlapLen, current + t[i]);
        used[i]--; // 回溯
    }
    return;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> t[i];
    cin >> startWord;

    dfs(0, startWord); // 从起始单词开始递归
    cout << maxx << endl; // 输出最长“龙”的长度
    return 0;
}
