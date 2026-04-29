#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
int n;

int main(){
    cin >> n;
    vector<int> A(n);
    double a_ = 0;
    double Da = 0;
    for(int i = 0; i < n; ++i){
        cin >> A[i];
        a_ += A[i];
    }

    a_ = a_/n;
    // cout << a_;
    for(int i = 0; i < n; ++i){
        Da += (A[i] - a_)*(A[i] - a_);
    }
    Da = Da/n;
    // cout << Da;
    for(int i = 0; i < n; ++i){
        printf("%f\n", (A[i] - a_)/sqrt(Da));        
    }


    return 0;
}