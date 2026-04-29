#include<iostream>

using namespace std;

//输入天数k
int k;

int main(){
    cin >> k;

    int passDay = 0;
    long long weixin = 0;
    for(int i = 1; ;++i){
        if(passDay + i <= k){
            passDay += i;
            weixin += i*i;
        } 
        else{
            weixin += (k-passDay)*i;
            break;
        }
    }

    cout << weixin << endl;

    return 0;
}