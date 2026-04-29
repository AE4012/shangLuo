#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;


int n, k;
long A[25];
int cnt = 0;

bool isPrime(long num){
    if(num <= 1){
        return false;
    }
    if(num == 2)    return true;
    if(num % 2 == 0){
        return false; 
    }
    for(int i = 3; i <= sqrt(num); i+=2){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

void calSpecial(int k, int start, long sum){
    if(k == 0){
        if(isPrime(sum)){
            cnt++;
        }
        return;
    }
    for(int i = start; i <= n; ++i){
        calSpecial(k-1, i+1, sum+A[i]);
    }
}

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> A[i];
    }

    calSpecial(k, 1, 0);

    cout << cnt << endl;

    return 0;
}