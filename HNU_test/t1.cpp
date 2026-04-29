#include<iostream>
#define ll long long

using namespace std;
int n, a, b;
ll result = 0;

int Cal_S(int x1, int x2, int y1, int y2){
    int temp_x, temp_y;
    if(x1 <= 0){
        if(x2 <= 0){
            return 0;
        }
        else if(x2 > 0 && x2 <= a){
            temp_x = x2;
        }
        else{
            temp_x = a;
        }
    }
    else if(x1 > 0 && x1 < a){
        if(x2 < a){
            temp_x = x2 - x1;
        }
        else{
            temp_x = a - x1;
        }
    }
    else{
        return 0;
    }

    if(y1 <= 0){
        if(y2 <= 0){
            return 0;
        }
        else if(y2 > 0 && y2 <= b){
            temp_y = y2;
        }
        else{
            temp_y = b;
        }
    }
    else if(y1 > 0 && y1 < b){
        if(y2 < b){
            temp_y = y2 - y1; 
        }
        else{
            temp_y = b - y1;
        }
    }
    else{
        return 0;
    }

    return temp_x * temp_y;
}

int main(){
    cin >> n >> a >> b;
    while(n--){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        result += Cal_S(x1, x2, y1, y2);
    }

    cout << result << endl;


    return 0;
}