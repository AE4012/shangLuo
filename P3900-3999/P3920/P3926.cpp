#include<iostream>

using namespace std;


int main(){
    long long a, c, p, q, r, x;
    cin >> a >> c >> p >> q >> r >> x;

    long long temp = a;
    long long time = x;

    //Step1: a->c
    if(temp < c){
        long long a2c = (c-temp)*p;
        if(time >= a2c){
            time -= a2c;
            temp = c;
        }
        else{
            temp += time/p;
            time = 0;
        }
    }

    //Step2: 解冻
    if(temp == c && time >= q){
        time -= q;
    }

    //Step3: 加热
    if(time > 0){
        temp += time/r;
    }

    cout << temp << endl;


    return 0;
}