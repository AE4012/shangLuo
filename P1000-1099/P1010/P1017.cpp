#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

string conversion(int n, int R){
    if(n == 0)  return "0";
    vector<char> result;
    while(n != 0){
        int yushu = n % R;
        n = n / R;
        if(yushu < 0){  //调整余数和商
            yushu += (-R);
            n += 1;
        }
        if(yushu >= 10){
            result.push_back('A' + (yushu - 10));
        }else{
            result.push_back('0' + yushu);
        }
    }
    reverse(result.begin(), result.end());
    return string(result.begin(), result.end());
}

int main(){
    int n, R;
    cin >> n >> R;
    string result = conversion(n, R);
    cout << n << "=" << result << "(base" << R << ")" << endl;

    return 0;
}