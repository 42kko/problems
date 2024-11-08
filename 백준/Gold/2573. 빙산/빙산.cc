#include <iostream>
#include <queue>
using namespace std;

/*
2차원 배열의 확산(bfs)
덩어리(배열 상하좌우로 연결되어있음) 하나가 주어질때
두 덩어리로 분리되는 시간을 출력

bfs로 덩어리 판단하고
시간 흐르고
다시 bfs로 덩어리 판단하고
*/

int board[305][305];
bool vist[305][305];
queue<pair<int,int> > q;
int n, m;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void resetVist() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vist[i][j] = false;
        }
    }
}

void nxtYear() {
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nxt_x = cur.second + dx[i];
            int nxt_y = cur.first + dy[i];
            if (nxt_x > m || nxt_x < 0 || nxt_y > n || nxt_y < 0) continue;
            if (board[nxt_y][nxt_x] == 0 || vist[nxt_y][nxt_x] == true) continue;
            vist[nxt_y][nxt_x] = true;
            q.push({nxt_y, nxt_x});
        }
        int tmp = 0;
        for (int i = 0; i < 4; i++) {
            if (vist[cur.first + dy[i]][cur.second + dx[i]] == false && board[cur.first + dy[i]][cur.second + dx[i]] == 0)
                tmp++;
        }
        board[cur.first][cur.second] = board[cur.first][cur.second] - tmp >= 0 ? board[cur.first][cur.second] - tmp : 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int cnt = 1;
    while (1) {
        for (int i = 0; i < n * m; i++) {
            if (board[i / m][i % m]) {
                q.push({i / m, i % m});
                vist[i / m][i % m] = true;
                break;
            }
        }
        nxtYear();
        int flag = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] > 0 && vist[i][j] == false) {
                    cout << cnt - 1;
                    return 0;
                }
                if (board[i][j])
                    flag = 1;
            }
        }
        if (!flag) {
            cout << "0";
            return 0;
        }
        resetVist();
        cnt++;
    }

    cout << "0";
}