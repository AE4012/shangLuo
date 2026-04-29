#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
int n, k;
int count = 0;

// 判断素数
bool isPrime(int num) {
    if (num <= 1) return false;  // 1 不是素数
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;  // 如果能整除，说明不是素数
    }
    return true;
}


void findCombinations(const vector<long> &a, int start, int k, int sum){
    if(k == 0){
        if(isPrime(sum)){
            count++;
        }
        return;
    }
    for(int i = start; i <= n; ++i){
        findCombinations(a, i+1, k-1, sum+a[i]);
    }
}

int main(){
    cin >> n >> k;
    vector<long> A(n+1);
    for(int i = 1; i <= n; ++i){
        cin >> A[i];
    }
    findCombinations(A, 1, k, 0);
    cout << count << endl;

    return 0;
}