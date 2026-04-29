#include<bits/stdc++.h>
#include<string>


using namespace std;

// input output
int n, k, x, y;
string s;

int main(){
    cin >> n >> k;
    
    for(int i = 0; i < n; ++i){
        cin >> x >> y >> s;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == 'f'){
                if((y + 1) <= n)
                    y = y + 1;
            }
            if(s[i] == 'b'){
                if((y - 1) >= 1)
                    y = y - 1;
            }
            if(s[i] == 'l'){
                if((x - 1) >= 1)
                    x = x - 1;
            }
            if(s[i] == 'r'){
                if((x + 1) <= n)
                    x = x + 1;
            }
        }
        cout << x << " " << y << endl;
    }


    return 0;
}