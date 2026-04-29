#include<iostream>
#include<vector>

using namespace std;

struct Carpets{
    int a,b;
    int g,k;
};

int main(){
    int n;
    cin >> n;
    vector<Carpets> carpet(n+1);
    for(int i = 1; i <= n; i++){
        cin >> carpet[i].a >> carpet[i].b >> carpet[i].g >> carpet[i].k;
    }

    int x, y;
    cin >> x >> y;

    for(int i = n; i > 0; i--){
        if(x>=carpet[i].a && x <= (carpet[i].a+carpet[i].g) && y >= carpet[i].b && y <= (carpet[i].b+carpet[i].k)){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}