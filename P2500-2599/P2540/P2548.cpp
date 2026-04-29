#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<set<string>> conditions(N);
    string input;

    for(int i = 0; i < M; ++i){
        for(int j = 0; j < N; ++j){
            cin >> input;
            conditions[j].insert(input);
        }
    }

    vector<string> result(N, "*");

    for(int i = 0; i < N; ++i){
        if(conditions[i].size() == 1){
            result[i] = *(conditions[i].begin());
        }
        cout << result[i];
        if(i < N - 1){
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}