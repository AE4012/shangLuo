#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
char c;
int numMem[100] = {0};
int currentSign = 1, tag = 1;
double xishu = 0;
char variable;

int main(){
    char c;
    while(cin.get(c) && c != '='){
        if(c == '-'){
            currentSign = -1;
            tag++;
        }
        if(c == '+'){
            currentSign = 1;
            tag++;
        }
        if(isdigit(c)){
            if(numMem[tag] == 0){
                numMem[tag] = (c - '0')*currentSign;
            }
            else{
                numMem[tag] = numMem[tag]*10 + (c - '0')*currentSign;
            }
        }
        if(isalpha(c)){
            variable = c;
            if(numMem[tag] != 0){
                xishu += numMem[tag];
                numMem[tag] = 0;
            }
            else{
                xishu += currentSign;
            }
            tag--;
        }
    }
    int midPoint = tag;
    tag++;
    currentSign = 1;

    while(cin.get(c) && c != '\n'){
        if(c == '-'){
            currentSign = -1;
            tag++;
        }
        if(c == '+'){
            currentSign = 1;
            tag++;
        }
        if(isdigit(c)){
            if(numMem[tag] == 0){
                numMem[tag] = (c - '0')*currentSign;
            }
            else{
                numMem[tag] = numMem[tag]*10 + (c - '0')*currentSign;
            }
        }
        if(isalpha(c)){
            variable = c;
            if(numMem[tag] != 0){
                xishu -= numMem[tag];
                numMem[tag] = 0;
            }
            else{
                xishu -= currentSign;
            }
            tag--;
        }
    }

    double NUM = 0;
    for(int i = 1; i <= tag; i++){
        if(i <= midPoint){
            NUM -= numMem[i];
        }
        else{
            NUM += numMem[i];
        }
    }

    double result = NUM / xishu;
    if (fabs(result) < 1e-9) {  // 误差阈值，接近于 0 的值
        result = 0.0;
    }
    printf("%c=%.3f\n", variable, result);

    return 0;
}