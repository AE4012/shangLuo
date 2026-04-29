#include<iostream>
#include<set>
#include<vector>
#include<string>

using namespace std;

int main(){
    //y = 2*x, z = 3*x;
    // x,y,z < 1000
    set<vector<int>> result;

    for(int x = 100; x <= 333; x++){
        int y = 2*x;
        int z = 3*x;
        set<int> temp;

        string sx = to_string(x);
        string sy = to_string(y);
        string sz = to_string(z);

        for(int i = 0; i < 3; i++){
            if(sx[i] != '0' && sy[i] != '0' && sz[i] != '0'){
                temp.insert(sx[i]);
                temp.insert(sy[i]);
                temp.insert(sz[i]);
            }
        }
        if(temp.size() == 9){
            cout << x << ' ' << y << ' ' << z << endl;
        }

    }

    return 0;
}