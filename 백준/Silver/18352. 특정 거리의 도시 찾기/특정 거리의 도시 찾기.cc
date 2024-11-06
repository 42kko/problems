#include <iostream>
#include <queue>
using namespace std;

/*
단방향 그래프가 주어질때 거리계산
bfs로 풀리는지 모르겠음
안풀릴 이유는 없는거같은데

시간 복잡도는 괜찮을지 의문
*/

vector<int> v[1000005];
int vist[300005] = {0,};
int n, m, k, x;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k >> x;
    for (int i = 0; i < m; i++) {
        int tmp, tmp1;
        cin >> tmp >> tmp1;
        v[tmp].push_back(tmp1);
    }
    
    queue<int> q;
    q.push(x);
    vist[x] = 1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (const int e : v[cur]) {
            if (vist[e]) continue;
            q.push(e);
            vist[e] = vist[cur] + 1;
        }
    }

    int flag = 0;
    for (int i = 1; i <= n; i++) {
        if (vist[i] - 1 == k) {
            cout << i << "\n";
            flag = 1;
        }
    }
    if (!flag)
        cout << "-1";
}