#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>

using namespace std;

struct Node {
    int x, y;
};

struct Station {
    int x, y, r, t;
};

bool inCoverage(const Node& node, const Station& station) {
    // 判断节点是否在基站的覆盖范围内
    return (node.x >= station.x - station.r && node.x <= station.x + station.r) &&
           (node.y >= station.y - station.r && node.y <= station.y + station.r);
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<Node> nodes(n);
    for (int i = 0; i < n; ++i) {
        cin >> nodes[i].x >> nodes[i].y;
    }

    vector<Station> stations(m);
    for (int i = 0; i < m; ++i) {
        cin >> stations[i].x >> stations[i].y >> stations[i].r >> stations[i].t;
    }

    // Dijkstra's Algorithm
    vector<int> dist(n, INT_MAX);  // 初始化距离为无穷大
    dist[0] = 0;  // 从节点1开始
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});  // {距离, 节点索引}
    
    while (!pq.empty()) {
        //top(), 最短距离
        int currentDist = pq.top().first;
        int currentNode = pq.top().second;
        
        pq.pop();

        if (currentDist > dist[currentNode]) continue; // 这条路径已经不是最短的了

        // 试图通过基站连接其他节点
        for (int i = 0; i < m; ++i) {
            Station& station = stations[i];
            if (inCoverage(nodes[currentNode], station)) {
                // 当前节点与基站有连接
                for (int j = 0; j < n; ++j) {
                    if (inCoverage(nodes[j], station) && dist[currentNode] + station.t < dist[j]) {
                        dist[j] = dist[currentNode] + station.t;
                        pq.push({dist[j], j});
                    }
                }
            }
        }
    }

    if (dist[n-1] == INT_MAX) {
        cout << "Nan" << endl;  // 无法到达节点n
    } else {
        cout << dist[n-1] << endl;  // 输出最短通讯延迟
    }

    return 0;
}
