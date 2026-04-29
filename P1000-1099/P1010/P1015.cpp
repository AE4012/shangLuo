#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// 将 N 进制表示的字符串逐位相加，返回新的 N 进制字符串
// 精确的加法
string add_baseN(const string& num1, const string& num2, int N){
    string result = "";
    int carry = 0;
    int len1 = num1.size(), len2 = num2.size();
    int max_len = max(len1, len2);

    //从最低位开始相加
    for(int i = 0; i < max_len; i++){
        int digit1 = 0, digit2 = 0;

        //处理进制数
        if(i < len1){
            char c1 = num1[len1 - i - 1];
            //十进制内
            if(isdigit(c1)){
                ///string -> num
                digit1 = c1 - '0';
            }
            else{
                digit1 = c1 + 10 - 'A';
            }
        }
        if(i < len2){
            char c2 = num2[len2 - i - 1];
            if(isdigit(c2)){
                digit2 = c2 - '0';
            }
            else{
                digit2 = c2 + 10 - 'A';
            }
        }

        int sum = digit1 + digit2 + carry;
        carry = sum/N;
        int digit = sum % N;

        if(digit < 10){
            result += (char)(digit + '0');
        }
        else{
            result += (char)(digit - 10 + 'A');
        }

    }
    if(carry > 0){
        if(carry < 10){
            result += (char)(carry + '0');
        }
        else{
            result += (char)(carry - 10 + 'A');
        }
    }

    reverse(result.begin(), result.end());
    return result;
}

// 检查一个字符串是否是回文
bool is_palindrome(const string& s) {
    int len = s.length();
    for (int i = 0; i < len / 2; ++i) {
        if (s[i] != s[len - i - 1]) {
            return false;
        }
    }
    return true;
}
bool isHuiwen(const string& s){
    string temp = s;
    reverse(temp.begin(), temp.end());

    int len = s.size();
    for(int i = 0; i < len/2; i++){
        if(s[i] != temp[i]){
            return false;
        }
    }
    return true;
}

int main() {
    int N; // 进制
    string M; // 初始数的字符串表示
    
    cin >> N;
    cin >> M;
    
    int steps = 0;
    string current_num = M;
    
    while (steps <= 30) {
        // 检查当前数是否是回文
        if (isHuiwen(current_num)) {
            cout << "STEP=" << steps << endl;
            return 0;
        }
        
        // 反转当前数
        string reversed_num = current_num;
        reverse(reversed_num.begin(), reversed_num.end());
        
        // 在 N 进制下将当前数和反转数相加
        current_num = add_baseN(current_num, reversed_num, N);
        
        steps++;
    }
    
    // 如果 30 步以内没有找到回文数
    cout << "Impossible!" << endl;
    
    return 0;
}
