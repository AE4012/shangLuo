#include<iostream>
#include<vector>

using namespace std;
int n;

struct  TreeNode{
    int left, right;
};

int getDepth(const vector<TreeNode>& tree, int node){
    if(node == 0)   return 0;
    int left = getDepth(tree, tree[node].left);
    int right = getDepth(tree, tree[node].right);
    return max(left, right) + 1;
}

int main(){
    cin >> n;
    vector<TreeNode> tree(n+1);
    for(int i = 1; i <= n; ++i){
        cin >> tree[i].left >> tree[i].right;
    }
    cout << getDepth(tree, 1) << endl;

    return 0;
}