#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n;

bool CompareString(const string &a, const string &b){
    return a+b > b+a;
}

int main(){
    cin >> n;
    vector<string> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    sort(a.begin(), a.end(), CompareString);


    string result = "";
    for(string s : a){
        result += s;
    }
    if(result[0] == '0'){
        result = "0";
    }
    cout << result << endl;


    return 0;
}