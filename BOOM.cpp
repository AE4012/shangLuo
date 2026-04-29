#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Monster {
    int x, y, hp;
};

int main() {
    int n;
    cin >> n;
    vector<Monster> monsters(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> monsters[i].x >> monsters[i].y >> monsters[i].hp;
    }

    // 按 x 坐标排序
    sort(monsters.begin(), monsters.end(), [](const Monster &a, const Monster &b) {
        return a.x < b.x;
    });

    // 预处理
    vector<int> leftMinX(n), leftMaxX(n), leftMinY(n), leftMaxY(n), leftMaxHP(n);
    vector<int> rightMinX(n), rightMaxX(n), rightMinY(n), rightMaxY(n), rightMaxHP(n);

    // 初始化左侧范围
    leftMinX[0] = monsters[0].x;
    leftMaxX[0] = monsters[0].x;
    leftMinY[0] = monsters[0].y;
    leftMaxY[0] = monsters[0].y;
    leftMaxHP[0] = monsters[0].hp;

    for (int i = 1; i < n; ++i) {
        leftMinX[i] = min(leftMinX[i - 1], monsters[i].x);
        leftMaxX[i] = max(leftMaxX[i - 1], monsters[i].x);
        leftMinY[i] = min(leftMinY[i - 1], monsters[i].y);
        leftMaxY[i] = max(leftMaxY[i - 1], monsters[i].y);
        leftMaxHP[i] = max(leftMaxHP[i - 1], monsters[i].hp);
    }

    // 初始化右侧范围
    rightMinX[n - 1] = monsters[n - 1].x;
    rightMaxX[n - 1] = monsters[n - 1].x;
    rightMinY[n - 1] = monsters[n - 1].y;
    rightMaxY[n - 1] = monsters[n - 1].y;
    rightMaxHP[n - 1] = monsters[n - 1].hp;

    for (int i = n - 2; i >= 0; --i) {
        rightMinX[i] = min(rightMinX[i + 1], monsters[i].x);
        rightMaxX[i] = max(rightMaxX[i + 1], monsters[i].x);
        rightMinY[i] = min(rightMinY[i + 1], monsters[i].y);
        rightMaxY[i] = max(rightMaxY[i + 1], monsters[i].y);
        rightMaxHP[i] = max(rightMaxHP[i + 1], monsters[i].hp);
    }


    int minTotalCost = INT_MAX;
    for (int t = 0; t < n - 1; ++t) {  // t 是分界点的索引
        int leftArea = (leftMaxX[t] - leftMinX[t] + 1) * (leftMaxY[t] - leftMinY[t] + 1);
        int leftCost = leftArea * leftMaxHP[t];

        int rightArea = (rightMaxX[t + 1] - rightMinX[t + 1] + 1) * (rightMaxY[t + 1] - rightMinY[t + 1] + 1);
        int rightCost = rightArea * rightMaxHP[t + 1];

        int totalCost = leftCost + rightCost;
        minTotalCost = min(minTotalCost, totalCost);
    }

    cout << minTotalCost << endl;
    return 0;
}
