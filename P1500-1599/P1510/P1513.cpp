#include<iostream>
#include<cmath>
#define pi 3.1415926535

using namespace std;

struct point{
    double x;
    double y;
}pre, now, first;

double Cal_changdu(const point a, const point b){
    return sqrt((a.x - b.x)*(a.x - b.x)+(a.y - b.y)*(a.y - b.y));
}

int main(){
    int N;
    double R;
    cin >> N >> R;

    double changdu = 0;
    for(int i = 0; i < N; ++i){
        if(i == 0){
            cin >> first.x >> first.y;
            pre = first;
        }
        else{
            cin >> now.x >> now.y;
            changdu += Cal_changdu(now, pre);
            pre = now;
        }
    }

    changdu += Cal_changdu(pre, first);
    changdu += 2*pi*R;

    printf("%.2f", changdu);

    return 0;
}