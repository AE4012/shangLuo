#include<iostream>
#include<algorithm>

using namespace std;

int main(){
    int school, mom;
    int maxUnhappy = 8, maxTime = 0;
    for(int i = 1; i <= 7; i++){
        cin >> school >> mom;
        if(school + mom > maxUnhappy){
            maxUnhappy = school + mom;
            maxTime = i;
        }
    }
    cout << maxTime << endl;
    

    return 0;
}