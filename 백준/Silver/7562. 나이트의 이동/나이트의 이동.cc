#include <iostream>
#include <queue>
using namespace std;

/*
나이트는 동서남북으로 이동
시작, 목표 위치를주고 최단거리를 구하는문제
dfs문제
*/

int c;
int a;
pair<int, int> s;
pair<int, int> t;
int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[8] = {-1, 1, 1, -1, -2, 2, 2, -2};
int vist[305][305];

void bfs(queue<pair<int, int> > &q, pair<int, int> &t, int &size) {
    while (!q.empty()) {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        if (cur_x == t.first && cur_y == t.second)
            break;
        for (int i = 0; i < 8; i++) {
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            if (vist[nx][ny])
                continue;
            if (nx < 0 || nx > size || ny < 0 || ny > size) 
                continue;
            q.push({nx, ny});
            vist[nx][ny] = vist[cur_x][cur_y] + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> c;
    for (int i = 0; i < c; i++) {
        cin >> a >> s.first >> s.second >> t.first >> t.second;
        queue<pair<int, int> > q;
        for (int j = 0; j < a; j++) {
            for (int k = 0; k < a; k++) {
                vist[j][k] = 0;
            }
        }
        q.push({s.first, s.second});
        vist[s.first][s.second] = 1;
        bfs(q, t, a) ;
        cout << vist[t.first][t.second] - 1 << '\n';
    }
}