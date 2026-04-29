#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct Changes{
    char before;
    char after;
    int num;
};

string sorigin;
int n, m;
int main(){
    getline(cin, sorigin);
    
    cin >> n;

    getchar();
    vector<Changes> Change(n);
    for(int i = 0; i < n; ++i)
    {  
        string changing;
        getline(cin , changing);
        
        Change[i].before = changing[1];
        Change[i].after = changing[2];
        Change[i].num = 1;
    }

    for(int i = 0; i < n; ++i){
        char temp;
        temp = Change[i].after;
        int cnt = 1;
        while (temp != Change[i].before)
        {
            for(int j = 0; j < n; ++j){
                if(temp == Change[j].before){
                    temp = Change[j].after;
                    break;
                }
            }
            cnt++;
        }
        Change[i].num = cnt;
    }
    cin >> m;
    while(m--){
        int k;
        cin >> k;
        string st = sorigin;

        for(int i = 1; i < sorigin.size() - 1; ++i){
            char temp = st[i];
            for(int j = 0; j < n; ++j){
                if(temp == Change[j].before){
                    int tt;
                    tt = k % Change[j].num;
                    if(tt == 0) break;
                    char tmp;
                    tmp = Change[j].after;
                    tt--;
                    while(tt > 0){
                        for(int p = 0; p < n; ++p){
                            if(tmp == Change[p].before){
                                tmp = Change[p].after;
                                break;
                            }
                        }
                        tt--;
                    }
                    st[i] = tmp;
                    break;
                }
            }
        }
        cout << st << endl;
    }

    return 0;
}
