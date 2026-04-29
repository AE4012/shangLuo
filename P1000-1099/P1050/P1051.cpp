#include<iostream>
#include<vector>

using namespace std;

struct elements{
    string name;
    int qimo;
    int banji;
    char ganbu;
    char xibu;
    int lunwen;
};

int main(){
    int N;//学生总数
    cin >> N;
    vector<elements> element(N);
    elements maxStudent;
    int maxValue = 0;
    int sumValue = 0;
    for(int i = 0; i < N; ++i){
        cin >> element[i].name >> element[i].qimo >> element[i].banji >> element[i].ganbu >> element[i].xibu >> element[i].lunwen;
        int nowValue = 0;
        if(element[i].qimo > 80 && element[i].lunwen>= 1){
            nowValue += 8000;
        }
        if(element[i].qimo > 85 && element[i].banji > 80){
            nowValue += 4000;
        }
        if(element[i].qimo > 90){
            nowValue += 2000;
        }
        if(element[i].qimo > 85 && element[i].xibu == 'Y'){
            nowValue += 1000;
        }
        if(element[i].banji > 80 && element[i].ganbu == 'Y'){
            nowValue += 850;
        }
        if(nowValue > maxValue){
            maxStudent = element[i];
            maxValue = nowValue;
        }
        sumValue += nowValue;
    }

    cout << maxStudent.name << endl;
    cout << maxValue << endl;
    cout << sumValue << endl;
    

    return 0;
}