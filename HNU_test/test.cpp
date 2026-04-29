#include<bits/stdc++.h>
using namespace std;

int main(){
    int a = 1, b = 2;
    cout << a + b << endl;
    
    // 这个可以?好吧也不行
    int c, d;
    c, d = 3, 4; 
    cout << c << " " << d << endl;
    
    /*
    这个也不行
    int e;
    [e] = {5};
    cout << e << endl;
    
    这个不行
    int e = f = 5;
    cout << e << " " << f << endl;
    */

    
    return 0;
}