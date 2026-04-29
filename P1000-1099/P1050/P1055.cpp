#include <iostream>
#include <string>
using namespace std;

int main() {
    string isbn;
    cin >> isbn;  // 输入 ISBN

    // 去掉 ISBN 中的 '-'，只保留数字部分
    string isbn_digits = "";
    for (char c : isbn) {
        if (c != '-') {
            isbn_digits += c;
        }
    }

    // 检查是否符合 9 个数字加 1 个识别码的规则
    if (isbn_digits.length() != 10) {
        cout << "Invalid ISBN" << endl;  // 假设不会遇到这种情况，因为题目保证格式正确
        return 0;
    }

    // 计算识别码
    int sum = 0;
    for (int i = 0; i < 9; ++i) {
        sum += (isbn_digits[i] - '0') * (i + 1);  // 累加加权和
    }
    int remainder = sum % 11;  // 计算余数

    // 识别码应该是余数，如果余数是 10，则识别码是 'X'
    char expected_check_digit = (remainder == 10) ? 'X' : '0' + remainder;

    // 获取输入的 ISBN 中的识别码
    char actual_check_digit = isbn_digits[9];

    // 判断识别码是否正确
    if (actual_check_digit == expected_check_digit) {
        cout << "Right" << endl;
    } else {
        // 如果不正确，输出正确的 ISBN
        isbn[12] = expected_check_digit;  // 修改原 ISBN 的识别码位置
        cout << isbn << endl;
    }

    return 0;
}
