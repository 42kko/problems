#include <iostream>
using namespace std;

/*
시간 제한때문에 dp로 해결해야함.
dp테이블에 상태를 위한 테이블 하나추가해야할듯
0 - 가로, 1 - 세로, 2 - 대각선
*/

int n;
bool board[40][40];
long long dp[40][40][3];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    dp[0][1][0] = 1;
    for (int i = 0; i < 32; i++) {
        for (int j = 0; j < 32; j++) {
            if (board[i][j]) continue;

            if (j > 0) {
                dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][2];
            }
            if (i > 0) {
                dp[i][j][1] += dp[i - 1][j][1] + dp[i - 1][j][2];
            }
            if (i > 0 && j > 0 && board[i - 1][j] == 0 && board[i][j - 1] == 0) {
                dp[i][j][2] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
            }
        }
    }

    cout << dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2];
}