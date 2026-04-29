
#include <iostream>
#include <vector>
using namespace std;

string trap(vector<int>& height) {
    height.push_back(0); 
    return "Code1";
}
string trap2(vector<int> height) {
    height.push_back(0); 
    return "Code2";
}
int main() {
    int n;
    cin >> n;  
    vector<int> height(n);
    for (int i = 0; i < n; ++i) {
        cin >> height[i];
    }
    cout << trap(height) << endl;
    
    for(int h : height) {
        cout << h << " ";
    }
    cout << trap2(height) << endl;
    
    for(int h : height) {
        cout << h << " ";
    }

    return 0;
}