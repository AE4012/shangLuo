#include <iostream>
using namespace std;

/*
把每一站中a的关系看作a的斐波那契数列，
而u的关系看作u的斐波那契数列
*/

/*
车站	1 	2	3	4	5	6	7
up	    a	b(未知)	a+b	a+2b	2a+3b	3a+5b	0
down	0	b	b	a+b	a+2b	2a+3b	m
people	a	a	2a	2a+b	3a+2b	m=4a+4b	0

*/

int main() {
    int a, n, m, x;
    cin >> a >> n >> m >> x;

    int A[25], B[25], people_a[25], people_b[25];

    A[1] = 1; A[2] = 0;
    B[1] = 0; B[2] = 1;
    people_a[1] = 1;  people_a[2] = 1;  
    people_b[1] = 0;  people_b[2] = 0;  

    for(int i = 3; i <= n; ++i){
        //up总系数
        A[i] = A[i-1] + A[i-2];
        B[i] = B[i-1] + B[i-2];
        people_a[i] = A[i]-A[i-1]+people_a[i-1];
        people_b[i] = B[i]-B[i-1]+people_b[i-1];
    }

    int b;
    if(people_b[n-1] != 0){
        b = (m - (people_a[n-1]*a))/people_b[n-1];
    }
    else{
        b = 0;
    }

    cout << people_a[x]*a + people_b[x]*b << endl;

    return 0;
}
