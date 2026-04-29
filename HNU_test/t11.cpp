#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const long long MOD = 1000000007;

struct Node {
    long long x, y, z;   // 节点的坐标(x, y, z)
    long long add_x, add_y, add_z;  // 区间加法标记
    long long mul;        // 区间乘法标记
    int rotate;           // 区间旋转标记（0: no rotation, 1: one rotation, 2: two rotations）
    
    Node() : x(0), y(0), z(0), add_x(0), add_y(0), add_z(0), mul(1), rotate(0) {}
};

// 线段树及懒标记数组
vector<Node> tree;
vector<bool> lazy_update;

int n, m;

void applyLazy(int node, int start, int end) {
    // 处理当前节点的懒标记，更新其值
    Node &cur = tree[node];
    
    if (cur.rotate > 0) {
        // 旋转操作
        for (int i = 0; i < cur.rotate; ++i) {
            swap(cur.x, cur.y);
            swap(cur.y, cur.z);
        }
        cur.rotate = 0;  // 旋转标记清除
    }

    if (cur.mul != 1) {
        // 乘法操作
        cur.x = cur.x * cur.mul % MOD;
        cur.y = cur.y * cur.mul % MOD;
        cur.z = cur.z * cur.mul % MOD;
        
        cur.add_x = cur.add_x * cur.mul % MOD;
        cur.add_y = cur.add_y * cur.mul % MOD;
        cur.add_z = cur.add_z * cur.mul % MOD;
        
        cur.mul = 1;  // 乘法标记清除
    }
    
    if (cur.add_x != 0 || cur.add_y != 0 || cur.add_z != 0) {
        // 加法操作
        cur.x = (cur.x + cur.add_x) % MOD;
        cur.y = (cur.y + cur.add_y) % MOD;
        cur.z = (cur.z + cur.add_z) % MOD;
        
        cur.add_x = cur.add_y = cur.add_z = 0;  // 加法标记清除
    }
}

void build(int node, int start, int end) {
    if (start == end) {
        tree[node].x = tree[node].y = tree[node].z = 0;
        tree[node].mul = 1;
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
    }
}

void updateRange(int node, int start, int end, int l, int r, long long a, long long b, long long c, long long k, int rot) {
    applyLazy(node, start, end);
    
    if (start > r || end < l) {
        return;
    }
    
    if (start >= l && end <= r) {
        // 完全覆盖
        if (rot == 1) {
            tree[node].rotate = (tree[node].rotate + 1) % 3;
        } else if (rot == 2) {
            tree[node].rotate = (tree[node].rotate + 2) % 3;
        }
        
        tree[node].add_x = (tree[node].add_x + a) % MOD;
        tree[node].add_y = (tree[node].add_y + b) % MOD;
        tree[node].add_z = (tree[node].add_z + c) % MOD;
        
        tree[node].mul = (tree[node].mul * k) % MOD;
        return;
    }
    
    int mid = (start + end) / 2;
    updateRange(2 * node, start, mid, l, r, a, b, c, k, rot);
    updateRange(2 * node + 1, mid + 1, end, l, r, a, b, c, k, rot);
}

long long queryRange(int node, int start, int end, int l, int r) {
    applyLazy(node, start, end);
    
    if (start > r || end < l) {
        return 0;
    }
    
    if (start >= l && end <= r) {
        long long res = (tree[node].x * tree[node].x % MOD + tree[node].y * tree[node].y % MOD + tree[node].z * tree[node].z % MOD) % MOD;
        return res;
    }
    
    int mid = (start + end) / 2;
    long long left = queryRange(2 * node, start, mid, l, r);
    long long right = queryRange(2 * node + 1, mid + 1, end, l, r);
    return (left + right) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    
    tree.resize(4 * n);
    
    build(1, 1, n);
    
    while (m--) {
        int type, l, r;
        cin >> type >> l >> r;
        
        if (type == 1) {
            long long a, b, c;
            cin >> a >> b >> c;
            updateRange(1, 1, n, l, r, a, b, c, 1, 0);
        } else if (type == 2) {
            long long k;
            cin >> k;
            updateRange(1, 1, n, l, r, 0, 0, 0, k, 0);
        } else if (type == 3) {
            updateRange(1, 1, n, l, r, 0, 0, 0, 1, 1);
        } else if (type == 4) {
            cout << queryRange(1, 1, n, l, r) << endl;
        }
    }
    
    return 0;
}
