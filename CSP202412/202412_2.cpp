#include<bits/stdc++.h>

using namespace std;

// input output
int n;  // n<10^5
int a[100005];
int b[100005];

struct cnum
{
    int w;
    int upmax;
    int downmax;
}c[100005];


int main(){
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        cin >> a[i];
    }
    c[0].w = a[0];
    for(int i = 1; i <= n; ++i)
    {
        cin >> b[i];
        c[i].w = c[i-1].w - b[i] + a[i];
    }
    //经过的最大值
    c[1].upmax = c[0].w;
    for (int i = 2; i <= n; i++)
    {
        if(c[i-1].w > c[i-1].upmax){
            c[i].upmax = c[i-1].w;
        }
        else{
            c[i].upmax = c[i-1].upmax;
        }
        cout << c[i].upmax << endl;
    }
    
    c[n].downmax = c[n].w;
    cout << c[n].downmax << endl;
    for(int i = n; i >= 1; --i){
        if(c[i].w > c[i+1].downmax){
            c[i].downmax = c[i].w;
        }
        else{
            c[i].downmax = c[i+1].w;
        }
        cout << c[i].downmax << endl;
    }

    for(int i = 1; i <= n; ++i){
        if(c[i].upmax > (c[i].downmax + b[i]))
            cout << c[i].upmax << ' ';
        else
            cout << c[i].downmax + b[i] << ' ';
    }

    return 0;
}