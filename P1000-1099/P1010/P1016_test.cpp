#include<bits/stdc++.h>
#include<deque>

uisng namespace std;

// input
double D1, C, D2, D[10], P[10];
int N;

//output
double ans = 0.0;

D[0] = 0;

struct pos{
    double price, oil;
    pos(double in_price, double in_oil) : price(in_price), oil(in_oil) {}
};


int main(){
    cin >> D1 >> C >> D2 >> P[0] >> N;
    for(int i = 1; i <= N; i++){
        cin >> D[i] >> P[i];
        if(D[i] - D[i-1] > C * D2){
            printf("No Solution\n");
            return 0;
        }
    }

    D[N+1] = D1;
    double nC = C;

    deque<pos> OIL;

    OIL.push_back(pos(P[0], C));
    ans += P[0] * C;

    for(int i = 1; i <= i+1; ++i){
        // 该路段耗油
        double oil_cost = (D[i] - D[i-1])/D2;

        while(!OIL.empty() && oil_cost > 0){
            pos p = OIL.front();
            OIL.pop_front();
            if(p.oil > oil_cost){
                nC -= oil_cost;
                OIL.push_front(pos(p.price, p.oil - oil_cost));
                break;
            }

            nC -= p.oil;
            oil_cost -= p.oil;
        }

        if(i == N+1){
            while(!OIL.empty()){
                ans -= OIL.front().price * OIL.front().oil;
                OIL.pop_front();
            }
            break;
        }

        while(!OIL.empty() && OIL.back().price > P[i]){
            ans -= OIL.back().price * OIL.back().oil;
            nC -= OIL.back().oil;
            OIL.pop_back();
        }

        ans += (C - nC) * P[i];
        OIL.push_back(pos(P[i], C - nC));

    }
    


    return 0;
}