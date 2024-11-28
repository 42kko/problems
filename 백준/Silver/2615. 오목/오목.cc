#include <iostream>
using namespace std;

int board[20][20];
// int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
// int dy[8] = {-1, 0, 1, -1, 0, 1, 1, -1};
int dx[4] = {-1, 1, 0, 1};
int dy[4] = {1, 1, 1, 0};

int straight(int x, int y, int dir_x, int dir_y, int dol) {
    int count = 0;
    int i = x, j = y;
    while (!(x > 19 || x < 0 || y > 19 || y < 0 || board[x][y] != dol)) {
        count++;
        x += dir_x;
        y += dir_y;
    }
    if (count < 5) return -1;
    int reverse_x;
    int reverse_y;
    switch (dir_x)
    {
    case 1:
        reverse_x = -1;
        break;
    case 0:
        reverse_x = 0;
        break;
    case -1:
        reverse_x = 1;
        break;
    default:
        break;
    }
    switch (dir_y)
    {
    case 1:
        reverse_y = -1;
        break;
    case 0:
        reverse_y = 0;
        break;
    default:
        break;
    }
    i += reverse_x;
    j += reverse_y;
    while (!(i > 19 || i < 0 || j > 19 || j < 0 || board[i][j] != dol)) {
        count++;
        i += reverse_x;
        j += reverse_y;
    }
    return count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (board[i][j] == 1 || board[i][j] == 2) {
                // for (int k = 0; k < 8; k++) {
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx > 19 || nx < 0 || ny > 19 || ny < 0 || board[nx][ny] != board[i][j]) continue;
                    auto count = straight(i, j, dx[k], dy[k], board[i][j]);
                    if (count == 5) {
                        // auto ans = check_six(i, j, dx[k], dy[k], board[i][j]);
                        // if (ans.first == 5) {
                        // cout << board[i][j] << '\n' << ans.second.first << ' ' << ans.second.second;
                        // }
                        cout << board[i][j] << '\n' << i + 1 << ' ' << j + 1;
                        return 0;
                    }
                }
            }
        }
    }
    cout << '0';
}