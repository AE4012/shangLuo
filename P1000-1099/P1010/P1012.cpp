#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
int n;

bool compare(const string &a, const string &b){
    return a + b > b + a;
}

int main(){
    cin >> n;
    vector<string> numbers(n);
    for(int i = 0; i < n; ++i){
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end(), compare);

    string result;
    for(const string &num : numbers){
        result += num;
    }

    if(result[0] == '0'){
        result = "0";
    }

    cout << result << endl;
    return 0;


    return 0;
}