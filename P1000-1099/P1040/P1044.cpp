#include <iostream>
using namespace std;

int n;  // 输入数列的长度
int count = 0;  // 记录所有可能的输出序列数

void dfs(int inp, int outp, int stackDepth){
    if(inp == n && stackDepth){
        count++;
        return;
    }
    //选择一：将一个数输入PUSH序列
    if(inp < n){
        dfs(inp + 1, outp, stackDepth + 1);
    }
    //选择二：将一个数输出pop
    if(stackDepth > 0){
        dfs(inp, outp + 1, stackDepth - 1);
    }
}

int main() {
    cin >> n;  // 读取输入
    dfs(0, 0, 0);

    cout << count << endl;
    return 0;
}
