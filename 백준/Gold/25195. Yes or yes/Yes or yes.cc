#include <iostream>
#include <stack>
#include <vector>
using namespace std;
/*
출발은 1번 정점부터 시작.
1번 정점부터 시작해서 그래프를 순회할때 S 노드를 안거칠수 있을까?
노드로 쭉 진행하다 S 노드에 도착하면 순회 정지
1번과 연결된 정점들을 탐색, dfs를 골라서 1에서 시작해 q.push가 안되는 시점에서 meet가 잇엇나 없엇나 판단
*/

int n, m, fan_size;
bool fan[100005];
bool vist[100005];
vector<int> v[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, u1;
        cin >> u >> u1;
        v[u].push_back(u1);
    }
    cin >> fan_size;
    for (int i = 0; i < fan_size; i++) {
        int tmp;
        cin >> tmp;
        fan[tmp] = true;
    }

    stack<int> s;
    s.push(1);
    vist[1] = true;
    while (!s.empty()) {
        int cur = s.top();
        s.pop();

        if (fan[cur])   
            continue;
        for (const int e : v[cur]) {
            if (vist[e]) continue;
            s.push(e);
            vist[e] = true;
        }

        if (!v[cur].size()) {
            cout << "yes";
            return 0;
        }
    }
    cout << "Yes";
}