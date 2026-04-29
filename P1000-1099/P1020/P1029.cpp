#include<iostream>

using namespace std;

int gcd(int a, int b){
    while(b != 0){
        int remainder = a % b;
        a = b; 
        b = remainder;
    }
    return a;
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int main(){
    int x0, y0;
    cin >> x0 >> y0;

    if(y0 % x0 != 0){
        cout << 0 << endl;
        return 0;
    }

    int target = y0 / x0;
    int count = 0;

    for(int a = 1; a*a <= target; ++a){
        if(target % a == 0){
            int b = target / a;
            if(gcd(a, b) == 1){
                if(a == b){
                    count += 1;
                }
                else{
                    count += 2;
                }
            }
        }
    }
    cout << count << endl;

    return 0;
}