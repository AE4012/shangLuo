#include <iostream>
#include <vector>
using namespace std;

// 判断是否是质数
bool is_prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    if(is_prime(n-4)){
        cout << "2 " << "2 " << n-4;
        return 0;
    }

    for(int i = 3; i < n; ++i){
        if((i%2) != 0 && is_prime(i)){
            for(int j = i; j < n; j++){
                if((j%2) != 0 && is_prime(j)){
                    if(is_prime(n-i-j)){
                        cout << i << ' ' << j << ' ' << n-i-j << endl;
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}
