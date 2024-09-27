#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define cost first 
#define node second

int n, m;
int src, des;
vector<pair<int,int> > obj[1005];
int d[1005];
int pre[1005] = { 0, };

int main() {
    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        obj[u].push_back({w,v});
    }
    cin >> src >> des;
    fill(d, d + n + 1, 1e9);
    d[src] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push({d[src], src});
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        if (d[cur.node] != cur.cost) continue;
        for (auto nxt : obj[cur.node]) {
            if (d[nxt.node] <= d[cur.node] + nxt.cost) continue;
            d[nxt.node] = d[cur.node] + nxt.cost;
            pre[nxt.node] = cur.node;
            pq.push({d[nxt.node], nxt.node});
        }
    }
    cout << d[des] << '\n';
    int cnt = 1;
    vector<int> path;
    path.push_back(des);
    while (pre[des] != src) {
        cnt++;
        path.push_back(pre[des]);
        des = pre[des];
    }
    cout << ++cnt << '\n';
    path.push_back(src);
    for (auto i = path.rbegin(); i != path.rend(); ++i) {
        cout << *i << ' ';
    }
}