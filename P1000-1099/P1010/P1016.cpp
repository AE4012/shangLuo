#include<bits/stdc++.h>
#include<deque>

using namespace std;
// input
// 两个城市之间的距离 D1、汽车油箱的容量 C（以升为单位）、每升汽油能行驶的距离 D2 、出发点每升汽油价格P和沿途油站数 N（N 可以为零），油站 i 离出发点的距离 Di 、每升汽油价格 Pi
double D1, C, D2, D[10], P[10];
int N;
// Output
double ans = 0.0;

struct pos{
    double price, oil;
	pos(double in_price, double in_oil) : price(in_price), oil(in_oil)  {}
};
deque<pos> OIL;
double nC;


int main(){
    cin >> D1 >> C >> D2 >> P[0] >> N;
	D[0] = 0;
    for(int i=1; i <= N; i++) {
		cin >> D[i] >> P[i];
		if(D[i] - D[i-1] > C * D2) {
			printf("No Solution\n");
			return 0;
		}
	}

	D[N+1] = D1;
	//现存油
	nC = C;
	//在初始位置加满油
	OIL.push_back(pos(P[0], C));
	ans += P[0]*C;
	
	for(int i = 1; i <= N+1; ++i){
		//这段路所需油
		double oil_cost = (D[i] - D[i-1])/D2;
		while(!OIL.empty() && oil_cost > 0){
			pos p = OIL.front();
			OIL.pop_front();
			if(p.oil > oil_cost)	//该价位油足够
			{
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
		while (!OIL.empty() && OIL.back().price > P[i])	
		{
			ans -= OIL.back().price * OIL.back().oil;
			nC -= OIL.back().oil;
			OIL.pop_back();
		}
		//加满
		ans += (C - nC) * P[i];
		OIL.push_back(pos(P[i], C - nC));
		nC = C;
	}
	

	printf("%.2lf\n", ans);
    return 0;
}