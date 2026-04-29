#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>

using namespace std;

struct parameters{
    double a;
    double b;
    double c;
    double d;
}parameter;

double f(double x){
    return parameter.a*x*x*x + parameter.b*x*x + parameter.c*x +parameter.d;
}

int main(){
    cin >> parameter.a >> parameter.b >> parameter.c >> parameter.d;
    
    double roots[3];
    int count = 0;

    for(double i = -100; i < 100 && count < 3; i += 0.5){
        double mid;
        double l = i;
        double r = i+1;
        if(!f(l)){
            roots[count++] = l;
        }

        if(f(i) * f(i+0.5) < 0){

            while (r-l >= 1e-3){
                mid = (l + r)/2;
                if(f(mid) * f(l) <= 0){
                    r = mid;
                }
                else{
                    l = mid;
                }
            }
            roots[count++] = (l+r)/2;
        }
    }

    // sort(roots, roots+3);
    cout << fixed << setprecision(2) << roots[0] << " " << roots[1] << " " << roots[2] << endl;

    return 0;
}