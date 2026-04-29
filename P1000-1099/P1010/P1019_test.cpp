#include <iostream>
#include <vector>
#include <string>

using namespace std;

//substr(index, i)
/*
1、输入n个字符串，访问次数0
2、输入一个字符串c
3、以c开头，访问次数+1
4、dfs(龙)  
    如果龙 > max, update
    对所有字符串，判断能否接上
    能接上则接，访问次数+1
    继续dfs
    回退字符串访问次数
5、最后输出ans
*/

string ss[25];
int n, mark[25] = {0}, ans = 0;  //个数,访问次数

string calcOverlap(string pre, string next){
    int lenp = pre.length(), lenn = next.length();
    for(int i = 1; i < min(lenp, lenn); ++i){
        if(pre.substr(lenp - i, i) == next.substr(0, i)){
            return pre.substr(0, lenp - i) + next;
        }
    }
    return "0";
}

void dfs(string dragon){
    if(dragon.size() > ans) ans = dragon.size();
    for(int i = 0; i < n; ++i){
        if(mark[i] >= 2)    continue;
        
        string s = calcOverlap(dragon, ss[i]);
        if(s != '0'){
            mark[i]++;
            dfs(s);
            mark[i]--;
        }
    }
}

int main(){
    char c;
    cin >> n;
    for(int i = 0; i < n; ++i)  cin >> ss[i];
    cin >> c;
    for(int i = 0; i < n; ++i){
        if(ss[i][0] == c)   //开头
        {
            mark[i]++;
            dfs(ss[i]);
            mark[i]--;
        }
    }

    cout << ans << endl;
    return 0;
}