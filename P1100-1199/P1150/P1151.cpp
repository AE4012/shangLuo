#include <iostream>
using namespace std;

int main() {
    int K;
    cin >> K;

    bool found = false;  // 标记是否找到符合条件的五位数

    // 遍历 10000 到 30000 之间的所有五位数
    for (int num = 10000; num <= 30000; ++num) {
        // 提取子数 sub1, sub2, sub3
        int sub1 = num / 100;       // 前三位
        int sub2 = (num / 10) % 1000; // 从第二位到第四位
        int sub3 = num % 1000;      // 从第三位到第五位

        // 检查子数是否都能被 K 整除
        if (sub1 % K == 0 && sub2 % K == 0 && sub3 % K == 0) {
            cout << num << endl;
            found = true;  // 找到符合条件的五位数
        }
    }

    // 如果没有找到符合条件的数
    if (!found) {
        cout << "No" << endl;
    }

    return 0;
}
