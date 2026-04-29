#include<iostream>
#include<vector>
#include<map>

using namespace std;
int n;

int Judges(string mima){
    if(mima.size() < 6) return 0;
    bool More3 = false, zimu = false, shuzi = false, teshu = false;
    map<char, int> comeon;
    for(char c : mima){
        if(!zimu && (isupper(c) || islower(c))){
            zimu = true;
        }
        if(!shuzi && isdigit(c)){
            shuzi = true;
        }
        if(!teshu && (c == '*' || c == '#')){
            teshu = true;
        }
        if(comeon.find(c) == comeon.end()){
            comeon[c] = 1;
        }
        else{
            comeon[c]++;
            if(comeon[c] > 2)   More3 = true;
        }
    }

    if(zimu && shuzi && teshu){
        if(More3){
            return 1;
        }
        else{
            return 2;
        }
    }
    else{
        return 0;
    }
}

int main(){
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        cout << Judges(s) << endl;
    }


    return 0;
}