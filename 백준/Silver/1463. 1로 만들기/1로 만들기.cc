#include <iostream>
#include <queue>
using namespace std;

int n;

int bfs(int n) {
    vector<int> dist(n + 1, 0);
    queue<int> q;
    q.push(n);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == 1) return dist[cur];
        if (cur % 3 == 0 && dist[cur / 3] == 0) {
            dist[cur / 3] = dist[cur] + 1;
            q.push(cur / 3);
        }
        if (cur % 2 == 0 && dist[cur / 2] == 0) {
            dist[cur / 2] = dist[cur] + 1;
            q.push(cur / 2);
        }
        if (cur - 1 > 0 && dist[cur - 1] == 0) {
            dist[cur - 1] = dist[cur] + 1;
            q.push(cur - 1);
        }
    }
    return 0;
}

int main() {
    cin >> n;
    int ans = bfs(n);
    cout << ans;
}