#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> A(N);
    int total = 0;

    for(int i = 0; i < N; ++i){
        cin >> A[i];
        total += A[i];
    }

    int target = total / N;

    int moves = 0;

    //计算每一个堆与目标的差值，有差值就必定需要移动
    for(int i = 0; i < N-1; ++i){
        int diff = A[i] - target;
        A[i+1] += diff;
        if(diff != 0){
            moves++;
        }
    }

    cout << moves << endl;

    return 0;
}