#include<iostream>
#include<vector>
#include<map>
#include<set>

using namespace std;
int n, m;


int main(){
    cin >> n >> m;
    map<int,int> SUM;
    map<int,int> NUM;
    for(int i = 0; i < n; ++i){
        int num;
        cin >> num;
        set<int> occur;
        while(num--){
            int a;
            cin >> a;
            if(SUM.find(a) == SUM.end()){
                SUM[a] = 1;
            }
            else{
                SUM[a]++;
            }
            occur.insert(a);
        }
        for(auto& oc : occur){
            if(NUM.find(oc) == NUM.end()){
                NUM[oc] = 1;
            }
            else{
                NUM[oc]++;
            }  
        }
    }

    for(int i = 1; i <= m; i++){
        cout << NUM[i] << " " << SUM[i] << endl;
    }

    return 0;
}