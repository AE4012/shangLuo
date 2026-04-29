#include<iostream>

using namespace std;

int main(){
    int k;
    cin >> k;

    int n = 0;
    double Sn = 0.0;
    while(Sn <= k){
        n++;
        Sn += 1.0/n;
    }
    cout << n << endl;

    return 0;
}