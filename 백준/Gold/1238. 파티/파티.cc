#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//N개의 마을 M개의 방향 그래프
//N으로 향하는 가장 많은 시간
// 시작점을 전부 잡고 계산해야함

#define cost first
#define node second

vector<pair<int,int> > obj[1005];
int d[1005];
int n, m, x;
int ans = 0;

int main() {
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
        obj[u].push_back({w,v});
    }
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    for (int i = 1; i <= n; i++) {
        if (i == x) continue;
        int src = i;
        fill(d, d + n + 1, 1e9);
        d[src] = 0;
        pq.push({d[src], src});
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if (d[cur.node] != cur.cost) continue;
            for (auto nxt : obj[cur.node]) {
                if (d[nxt.node] <= d[cur.node] + nxt.cost) continue;
                d[nxt.node] = d[cur.node] + nxt.cost;
                pq.push({d[nxt.node], nxt.node});
            }
        }
        int tmp = d[x];
        fill(d, d + n + 1, 1e9);
        d[x] = 0;
        pq.push({d[x], x});
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if (d[cur.node] != cur.cost) continue;
            for (auto nxt : obj[cur.node]) {
                if (d[nxt.node] <= d[cur.node] + nxt.cost) continue;
                d[nxt.node] = d[cur.node] + nxt.cost;
                pq.push({d[nxt.node], nxt.node});
            }
        }
        int tmp1 = d[i];
        ans = max(ans, tmp + tmp1);
    }
    cout << ans;
}