#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

// 检查密码安全级别
int checkPasswordSecurity(const string& password) {
    if (password.length() < 6) return 0;  // 如果长度小于6，直接返回低安全度

    bool zimu = false, hasDigit = false, hasSpecial = false, liangci = false;
    unordered_map<char, int> charCount;

    // 遍历密码中的每个字符
    for (char c : password) {
        // 统计字符的出现次数
        charCount[c]++;
        
        // 判断字符种类
        if (!zimu && ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) zimu = true;
        if (!hasDigit && isdigit(c)) hasDigit = true;
        if (!hasSpecial && (c == '*' || c == '#')) hasSpecial = true;
    }

    for (auto& entry : charCount) {
        if (entry.second > 2) liangci = true;
    }

    if(zimu && hasDigit && hasSpecial){
        if(!liangci){
            return 2;
        }
        else{
            return 1;
        }
    }
    else{
        return 0;
    }
}

int main() {
    int n;
    cin >> n;

    // 对每个密码进行判断并输出安全级别
    while (n--) {
        string password;
        cin >> password;
        cout << checkPasswordSecurity(password) << endl;
    }

    return 0;
}
