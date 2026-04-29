#include<bits/stdc++.h>
#include<map>

using namespace std;

//input
int N;
//output
int M;

map<int, int> data;

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;
        if(data.find(temp) == data.end()){
            data[temp] = 1;
        }
    }
    
    M = data.size();
    cout << M << endl;
    for(auto it = data.begin(); it != data.end(); it++){
        cout << it->first << " ";
    }

    return 0;
}   