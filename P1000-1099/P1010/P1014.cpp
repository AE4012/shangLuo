#include<iostream>

using namespace std;

int main(){
    int N;
    cin >> N;

    int total = 1;
    int lineNum = 1;

    while(N > total){
        lineNum++;  //增加到当前行数量
        total += lineNum;   //总计
    }

    int position = lineNum - (total - N);
    int num, dem;

    if(lineNum % 2 == 1){
        num = lineNum - position + 1;
        dem = position;
    }
    else{
        num = position;
        dem = lineNum - position + 1;
    }

    cout << num << '/' << dem << endl;

    return 0;
}