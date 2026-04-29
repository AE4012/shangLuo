#include<iostream>
#include<vector>

using namespace std;
int numMem[100] = {0};
int currentSign = 1;
int index = 1;
double xishu = 0;
char variable;

int main(){
    char c;
    while(cin.get(c) && c != '='){
        if(c =='-'){
            currentSign = -1;
            ++index;
        }
        if(c == '+'){
            currentSign = 1;
            ++index;
        }
        if(isdigit(c)){
            if(numMem[index] == 0){
                numMem[index] = (c - '0')*currentSign;
            }
            else{
                numMem[index] = numMem[index] * 10 + (c - '0')*currentSign;
            }
        }
        if(isalpha(c)){
            variable = c;
            if(numMem[index] == 0){
                xishu += currentSign;
            }
            else{
                xishu += numMem[index];
                numMem[index] = 0;
            }
            index--;
        }
    }

    int midpoint = index;
    ++index;
    currentSign = 1;

     while(cin.get(c) && c != '\n'){
        if(c =='-'){
            currentSign = -1;
            ++index;
        }
        if(c == '+'){
            currentSign = 1;
            ++index;
        }
        if(isdigit(c)){
            if(numMem[index] == 0){
                numMem[index] = (c - '0')*currentSign;
            }
            else{
                numMem[index] = numMem[index] * 10 + (c - '0')*currentSign;
            }
        }
        if(isalpha(c)){
            variable = c;
            if(numMem[index] == 0){
                xishu -= currentSign;
            }
            else{
                xishu -= numMem[index];
                numMem[index] = 0;
            }
            index--;
        }
    }

    double totalNum = 0;

    for(int i = 1; i <= index; ++i){
        if(i <= midpoint){
            totalNum -= numMem[i];
        }
        else{
            totalNum += numMem[i];
        }
    }


    if(totalNum / xishu == 0){
        printf("%c=0.000\n", variable);
    }
    else{
        printf("%c=%.3lf\n",variable, totalNum / xishu);
    }

    return 0;
}