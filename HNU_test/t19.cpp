#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n;

struct Score
{
    int w;
    int score;
};


int main(){
    cin >> n;
    vector<Score> ScoreS(n);
    long long result = 0;

    for(int i = 0; i < n; ++i){
        cin >> ScoreS[i].w >> ScoreS[i].score;
        result += ScoreS[i].w*ScoreS[i].score;
    }

    if(result < 0){
        result = 0;
    }
    cout << result << endl;

    return 0;
}