#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<pair<int, int> > obj[1005];
int dist[1005];
int pre[1005];
int vist[1005];
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        obj[u].push_back({w, v});
    }
    fill(dist, dist + n + 1, -1e9);
    dist[1] = 0;

    for (int i = 0; i < n; i++) {
        for (int u = 1; u <= n; u++) {
            for (auto nxt : obj[u]) {
                int w = nxt.first, v = nxt.second;
                if (dist[u] != 1e9 && dist[v] < dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pre[v] = u;
                }
            }
        }
    }

    queue<int> q;
    bool cycle = 0;
    for (int u = 1; u <= n; u++) {
        for (auto nxt : obj[u]) {
            int w = nxt.first, v = nxt.second;
            if (dist[u] != 1e9 && dist[v] < dist[u] + w) {
                q.push(v);
                break;
            }
        }
        if (!q.empty()) break; 
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == n) {
            cout << "-1";
            return 0;
        }
        for (auto nxt : obj[cur]) {
            if (vist[nxt.second] == 1) continue;
            q.push(nxt.second);
            vist[nxt.second] = 1;
        }
    }

    if (dist[n] == -1e9) {
        cout << "-1";
        return 0;
    }

    vector<int> path;
    int cur = n;
    while (cur != 1) {
        path.push_back(cur);
        cur = pre[cur];
    }
    path.push_back(1);


    for (auto it = path.rbegin(); it != path.rend(); ++it) {
        cout << *it << ' ';
    }

    return 0;
}