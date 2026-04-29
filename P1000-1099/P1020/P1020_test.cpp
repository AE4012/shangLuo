#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int maxCatch, maxSystem;
vector<int> missiles;
int n;
//389 207 155 300 299 170 158 65
// 1   2   3   2   3   4   5   6
// 1   1   1   2   2   2   2   2

int findNonIncreasing(const vector<int>& missiles){
    vector<int> ends;

    for(int height : missiles){
        auto it = upper_bound(ends.begin(), ends.end(), height, greater<int>());
        if(it == ends.end()){
            ends.push_back(height);
        }
        else{
            *it = height;
        }

    }
    return ends.size();
}

int findDecreasing(const vector<int>& missiles){
    vector<int> ends;

    for(int height : missiles){
        auto it = lower_bound(ends.begin(), ends.end(), height);
        if(it == ends.end()){
            ends.push_back(height);
        }
        else{
            *it = height;
        }
    }
    return ends.size();
}

int main(){
    while(cin >> n && n != EOF){
        missiles.push_back(n);
    }
    cout << findNonIncreasing(missiles) << endl;
    cout << findDecreasing(missiles) << endl;

    return 0;
}