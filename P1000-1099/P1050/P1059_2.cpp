#include<bits/stdc++.h>
#include<set>

using namespace std;

//input
int N;
//output
int M;

set<int> data;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        data.insert(temp);
    }

    M = data.size();
    cout << M << endl;  
    for(auto it = data.begin(); it != data.end(); it++){
        cout << *it << " ";
    }

    return 0;
}