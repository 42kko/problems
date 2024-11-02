#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int vist[100005] = {0,};
int n, m, r;
vector<int> v[200005];

int main() {
    cin >> n >> m >> r;
    for (int i = 0; i < m; i++) {
        int tmp;
        int tmp1;
        cin >> tmp >> tmp1;
        v[tmp].push_back(tmp1);
        v[tmp1].push_back(tmp);
    }
    for (int i = 0; i < m; i++) {
        sort(v[i].begin(), v[i].end());
    }

    vist[r] = 1;
    queue<int> q;
    q.push(r);
    int cnt = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < v[cur].size(); i++) {
            int nxt = v[cur][i];
            if (!vist[nxt]) {
                vist[nxt] = ++cnt;
                q.push(nxt);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << vist[i] << '\n';
    }
}