#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int n, mark[25] = {0}, ans = 0;
string ss[25];
char head;

string CalOverlop(string dragon, string next){
    int len1 = dragon.length(), len2 = next.length();
    for(int i = 1; i < min(len1, len2); ++i){
        if(dragon.substr(len1 - i, i) == next.substr(0, i)){
            return dragon.substr(0, len1 - i) + next;
        }
    }
    return "0";
}

void dfs(string dragon){
    if(ans < dragon.size()) ans = dragon.size();
    for(int i = 0; i < n; ++i){
        if(mark[i] >= 2)    continue;
        string s = CalOverlop(dragon, ss[i]);

        if(s != "0"){
            mark[i]++;
            dfs(s);
            mark[i]--;
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> ss[i];
    }

    cin >> head;

    for(int i = 0; i < n; ++i){
        if(ss[i][0] == head){
            mark[i]++;
            dfs(ss[i]);
            mark[i]--;
        }
    }
    cout << ans << endl;

    return 0;
}