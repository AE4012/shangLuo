#include<iostream>
#include<stack>
#include<string>

using namespace std;

string n;
int k;

int main(){
    cin >> n >> k;
    stack<char> stk;

    for(char digit : n){
        while(k > 0 && !stk.empty() && stk.top() > digit){
            stk.pop();
            k--;
        }   
        stk.push(digit);
    }

    while (k > 0)
    {
        stk.pop();
        k--;
    }

    string result = "";
    while (!stk.empty() && stk.top() == '0')
    {
        stk.pop();
    }
    
    
    while(!stk.empty()){
        result = stk.top() + result;
        stk.pop();
    }
    if(result.empty()){
        result = "0";
    }


    cout << result << endl;

    return 0;
}