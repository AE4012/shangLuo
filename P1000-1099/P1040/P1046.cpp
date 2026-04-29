#include<iostream>

using namespace std;

int main(){
    int apple[10];
    for(int i = 0; i < 10; i++){
        cin >> apple[i];
    }

    int height;
    cin >> height;
    height += 30;
    
    int count = 0;
    for(int i = 0; i < 10; i++){
        if(height >= apple[i])
            count++;
    }

    cout << count << endl;

    return 0;
}