#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>

using namespace std;

int main(){
    double v, theta;
    cin >> v >> theta;

    const double g = 10.0; // 重力加速度

    // 分解速度
    double vy = v * cos(theta);
    double vx = v * sin(theta);

    // 计算 x0 和 y0
    double x0 = (vx * vy) / g;
    double y0 = (x0/2)*vy/vx;

    // 输出结果，保留 15 位小数
    printf("%.3lf %.3lf\n", x0, y0);

    return 0;
}