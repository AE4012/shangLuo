#include<iostream>
#include<vector>

using namespace std;

struct score{
    int W;
    int L;
};



int main(){
    char inp;

    int W_11 = 0, L_11 = 0;
    int W_21 = 0, L_21 = 0;
    
    vector<score> W11;
    vector<score> W21;
    

    while(cin >> inp){
        if(inp == 'E'){
            break;
        }

        if(inp == 'W'){
            W_11++;
            W_21++;
            if(W_11 >= 11 && W_11-L_11 >= 2){
                score tag;
                tag.W = W_11;
                tag.L = L_11;
                W11.push_back(tag);
                W_11 = 0;
                L_11 = 0;
            }
            if(W_21 >= 21 && W_21 - L_21 >= 2){
                score tag;
                tag.W = W_21;
                tag.L = L_21;
                W21.push_back(tag);
                W_21 = 0;
                L_21 = 0;
            }
        }
        if(inp == 'L'){
            L_11++;
            L_21++;
            if(L_11 >= 11 && L_11-W_11 >= 2){
                score tag;
                tag.W = W_11;
                tag.L = L_11;
                W11.push_back(tag);
                W_11 = 0;
                L_11 = 0;
            }
            if(L_21 >= 21 && L_21-W_21 >= 2){
                score tag;
                tag.W = W_21;
                tag.L = L_21;
                W21.push_back(tag);
                W_21 = 0;
                L_21 = 0;                
            }
        }
    }

    score tag;
    tag.W = W_11;
    tag.L = L_11;
    W11.push_back(tag);

    tag.W = W_21;
    tag.L = L_21;
    W21.push_back(tag);

    for(auto& w : W11){
        cout << w.W << ":" << w.L << endl;
    }
    cout << endl;
    for(auto& w : W21){
        cout << w.W << ":" << w.L << endl;
    }

    return 0;
}