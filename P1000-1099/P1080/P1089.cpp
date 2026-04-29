#include<iostream>

using namespace std;

int main(){
    int To_mon = 0, Collect = 0;
    int cost;
    for(int i = 1; i <= 12; ++i){
        cin >> cost;
        Collect += 300;
        if(cost > Collect){
            cout << "-" << i << endl;
            return 0;
        }
        Collect -= cost;
        while(Collect >= 100){
            To_mon += 100;
            Collect -= 100;
        }
    }

    cout << To_mon*1.2 + Collect << endl;


    return 0;
}