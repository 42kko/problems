#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// n개의 노드, m개의 간선
// A, B노드가 주어질때 최소비용을 출력
#define cost first
#define node second

int n, m, src, des;
vector<pair<int,int> > obj[1005];
int d[1005];
const int INF = 1e9+10;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, p;
        cin >> u >> v >> p;
        obj[u].push_back({p, v});
    }
    cin >> src >> des;
    fill(d, d + n + 1, INF);
    d[src] = 0;
    
    priority_queue<pair<int,int> , vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push({d[src], src}); // 비용, 시작점
    while (!pq.empty()) {
        auto cur = pq.top(); 
        pq.pop();
        if (d[cur.node] != cur.cost) continue; // d[]와 지금 cost 비교
        for (auto nxt : obj[cur.node]) {
            if (d[nxt.node] <= d[cur.node] + nxt.cost) continue;
            d[nxt.node] = d[cur.node] + nxt.cost;
            pq.push({d[nxt.node], nxt.node});
        }
    }
    cout << d[des];
}