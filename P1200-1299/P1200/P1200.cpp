#include<iostream>

using namespace std;

int main(){
    string huixin, duiwu;

    cin >> huixin >> duiwu;

    int numh = 1, numd = 1;

    for(char h : huixin){
        numh *= static_cast<int>(h-'A'+1);
    }
    for(char d : duiwu){
        numd *= static_cast<int>(d-'A'+1);
    }

    if(numh%47 == numd%47){
        cout << "GO" << endl;
    }
    else{
        cout << "STAY" << endl;
    }

    return 0;
}