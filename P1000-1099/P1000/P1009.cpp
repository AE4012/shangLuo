//-*- coding:utf-8 -*-
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>    

using namespace std;

string multiply(const string& num1, const string& num2) {
    int len1 = num1.size();
    int len2 = num2.size();
    vector<int> result(len1 + len2, 0); // 用于存储乘积的每一位

    // 从最低位开始逐位相乘
    for (int i = len1 - 1; i >= 0; --i) {
        for (int j = len2 - 1; j >= 0; --j) {
            int mul = (num1[i] - '0') * (num2[j] - '0'); // 当前位乘积
            int p1 = i + j, p2 = i + j + 1;
            int sum = mul + result[p2]; // 累加到对应的结果位置

            result[p2] = sum % 10; // 处理当前位
            result[p1] += sum / 10; // 处理进位
        }
    }

    // 将结果从数组转化为字符串，跳过前导零
    string product = "";
    for (int num : result) {
        if (!(product.empty() && num == 0)) { // 去除前导零
            product += to_string(num);
        }
    }

    // 如果结果是空的，说明乘积是0
    return product.empty() ? "0" : product;
}

string add(string a, string b) {
    string result = "";
    int carry = 0;

    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0'; // 取出当前位
        if (j >= 0) sum += b[j--] - '0'; // 取出当前位
        result += (sum % 10) + '0'; // 保存当前位
        carry = sum / 10; // 计算进位
    }

    reverse(result.begin(), result.end()); // 反转结果
    return result;
}


int main(){
    int n;
    cin >> n;

    string sum = "0"; // 存储总和
    string factorial = "1"; // 计算阶乘

    // 计算 1! 到 n!
    for (int i = 1; i <= n; i++) {

        factorial = multiply(factorial, to_string(i)); // 计算 i!
        sum = add(sum, factorial); // 累加
    }

    cout << sum << endl; // 输出结果


    return 0;
}
