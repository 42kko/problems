#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
전체사람 n
두번째줄에 대한 계산을 출력해야함
세번째 줄에 관계 m, 이후 m만큼의 관계가 주어진다.
관계는 x는 부모 y는 본인
이때의 촌수를 계산

1의 자식은 2,3
2의 자식은 7,8,9
4의 자식은 5,6
3에서 7로 가려면 3 -> 1 -> 2 -> 7  3촌이관계이다.

bfs로 돌려볼까
1,2 에서 최상위 노드를 가고 최상위 노드가 다르다면 -1, 같다면 경로비용 출력
*/

int n, m;
int in[2];
vector<int> v[105];
bool vist[105] = {0,};

int main() {
    cin >> n >> in[0] >> in[1] >> m;
    for (int i = 0; i < m; i++) {
        int tmp, tmp1;
        cin >> tmp >> tmp1;
        v[tmp].push_back(tmp1);
        v[tmp1].push_back(tmp);
    }

    int ans = 0;
    queue<pair<int, int> > q;
    q.push({in[0], 0});
    while (!q.empty()) {
        int cur = q.front().first;
        int deep = q.front().second;
        q.pop();

        if (cur == in[1]) {
            ans = deep;
            break;
        }
        for (const int nxt : v[cur]) {
            if (!vist[nxt]) {
                vist[nxt] = true;
                q.push({nxt, deep + 1});
            }
        }
    }
    if (ans)
        cout << ans;
    else
        cout << "-1";
}