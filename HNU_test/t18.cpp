#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;
int m;
int ONE = 0;
int ZERO = 0;
int MAXthreshold;

struct Student{
    int y;
    int one;
    int zero;
};

bool cmp(Student a, Student b){
    return a.y < b.y;
}

int main(){
    cin >> m;

    set<int> threshold;
    vector<Student> Stus;

    for(int i = 0; i < m; ++i){
        int y, result;
        cin >> y >> result;
        if(threshold.find(y) == threshold.end()){
            Student stu;
            threshold.insert(y);
            stu.y = y;
            if(result == 1){
                stu.one = 1;
                stu.zero = 0;
                ONE++;
            }
            else{
                stu.one = 0;
                stu.zero = 1;
                ZERO++;
            }
            Stus.push_back(stu);
        }
        else{
            for(auto& s : Stus){
                if(s.y == y){
                    if(result == 1){
                        s.one += 1;
                        ONE++;
                    }
                    else{
                        s.zero += 1;
                        ZERO++;
                    }
                    break;
                }
            }
        }
    }
    
    sort(Stus.begin(), Stus.end(), cmp);
    MAXthreshold = Stus[0].y;
    int tempO = ONE;
    int tempZ = 0;
    int isRight = tempO + tempZ;
    int tempMax = isRight;
    for(int i = 1; i < threshold.size(); ++i){
        tempO -= Stus[i-1].one;
        tempZ += Stus[i-1].zero;
        isRight = tempO + tempZ;
        if(isRight >= tempMax){
            MAXthreshold = Stus[i].y;
            tempMax = isRight;
            // cout << tempMax;
        }
    }

    cout << MAXthreshold << endl;

    return 0;
}