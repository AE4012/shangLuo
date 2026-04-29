#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 用于将整数 n 分解为幂次方表示
string powerRepresentation(int n) {
    if (n == 0) return ""; // 特殊情况，n = 0 的时候不输出
    if (n == 1) return "2(0)"; // 2^0 表示为 2(0)
    
    string result = "";
    vector<int> powers;
    
    // 找出二进制中为 1 的位，并记录对应的幂次
    int powerIndex = 0;
    while (n > 0) {
        if (n % 2 == 1) {
            powers.push_back(powerIndex);
        }
        n /= 2;
        powerIndex++;
    }
    
    // 构造表达式
    for (int i = powers.size() - 1; i >= 0; i--) {
        if (i != powers.size() - 1) result += "+"; // 加号分隔
        
        // 对幂次进一步处理
        if (powers[i] == 1) {
            result += "2"; // 2^1 直接表示为 2
        } else if (powers[i] == 0) {
            result += "2(0)"; // 2^0 表示为 2(0)
        } else {
            result += "2(" + powerRepresentation(powers[i]) + ")"; // 递归处理
        }
    }
    
    return result;
}

int main() {
    int n;
    cin >> n; // 读取输入
    cout << powerRepresentation(n) << endl; // 输出结果
    return 0;
}
