#include<iostream>
#include<vector>

using namespace std;
int predict;

struct datas{
    int value;
    int volumn;
};

int main(){
    cin >> predict;
    int baseVolumn, baseValue;
    cin >> baseValue >> baseVolumn;
    
    vector<datas> data;
    data.push_back({baseValue, baseVolumn});
    int index = 0;

    int value, volumn;
    while(cin >> value >> volumn, value != -1 && volumn != -1){
        if(value - data[index].value > 1){
            int temp = (data[index].volumn - volumn)/(value - data[index].value);
            while(value - data[index].value > 1){
                data.push_back(data[index].value + 1, data[index].volumn - temp);
                index++;
            }
        }
        data.push_back(value, volumn);
        index++;
    }

    int decreaseRate;
    cin >> decreaseRate;

    

    return 0;
}