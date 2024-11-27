#include <iostream>
#include <vector>
using namespace std;

int n;
int board[1005];
int dp[1005];
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (board[i] > board[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    cout << n -ans;
}