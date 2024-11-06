#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> v[300005];
int vist[300005]; // 방문 여부와 거리를 저장
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
    vist[x] = 1; // 시작 노드의 거리는 1 (방문 표시)

    vector<int> result; // 거리 k인 노드를 저장

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (const int e : v[cur]) {
            if (vist[e]) continue; // 이미 방문한 노드는 스킵
            vist[e] = vist[cur] + 1; // 거리 갱신
            if (vist[e] - 1 == k) { // 거리 k인 노드
                result.push_back(e);
            } else if (vist[e] - 1 < k) { // 거리 k 이하인 경우만 큐에 삽입
                q.push(e);
            }
        }
    }

    if (result.empty()) {
        cout << "-1\n"; // 거리 k인 노드가 없는 경우
    } else {
        // 결과를 오름차순으로 출력
        sort(result.begin(), result.end());
        for (int r : result) {
            cout << r << "\n";
        }
    }

    return 0;
}