#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    vector<int> freq(26, 0);
    string line;

    for(int i = 0; i < 4; ++i){
        getline(cin, line);
        for(char ch : line){
            if(ch >= 'A' && ch <= 'Z'){
                freq[ch - 'A']++;
            }
        }
    }

    // 找到最大频率，决定图表高度
    int max_freq = *max_element(freq.begin(), freq.end());

    //从顶部到底部生成柱状图
    for(int i = max_freq; i > 0; --i){
        bool first = true;
        for(int j = 0; j < 26; ++j){
            if(!first) cout << " ";
            if(freq[j] >= i){
                cout << "*";
            }
            else{
                cout << " ";
            }
            first = false;
        }
        cout << endl;
    }

    // 输出字母底部行
    for (int i = 0; i < 26; ++i) {
        if (i > 0) cout << " ";
        cout << char('A' + i);
    }
    cout << endl;


    return 0;
}