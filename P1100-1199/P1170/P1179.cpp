#include<iostream>
#include<string>

using namespace std;

int main(){
    int L, R;
    cin >> L >> R;
    int count = 0;

    for(int i = L; i <= R; ++i){
        string si = to_string(i);
        
        for(char s : si){
            if(s == '2'){
                count++;
            }
        }
    }
    cout << count << endl;

    return 0;
}