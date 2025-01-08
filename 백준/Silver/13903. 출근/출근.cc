#include <iostream>
#include <queue>
using namespace std;

/*
시작지점에서 bfs 돌려버리면 될듯
*/

int board[1005][1005];
bool vist[1005][1005];
int r, c;
int n;
int role[15][2];
int ans;
queue<pair<pair<int, int>, int> > q;

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
            if (i == 0 && board[i][j] == 1) {
                q.push({{i, j}, 0});
                vist[i][j] = 1;
            }
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> role[i][0] >> role[i][1];
    }
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int x = cur.first.first;
        int y = cur.first.second;
        int step = cur.second;

        if (x == r - 1) {
            cout << step;
            return 0;
        }
        for (int i = 0; i < n; i++) {
            int nx = x + role[i][0];
            int ny = y + role[i][1];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c || board[nx][ny] != 1 || vist[nx][ny] == 1) continue;
            vist[nx][ny] = true;
            q.push({{nx, ny}, step + 1});
        }
    }
    cout << "-1";
}  