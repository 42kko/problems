#include <iostream>
using namespace std;

/*
n의 수가 주어질때, i부터 j번째 까지의 수의 합

*/

int n, m;
int board[100005];
int dp[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    dp[1] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> board[i];
        dp[i] = board[i] + dp[i - 1];
    }
    for (int i = 0; i < m; i++) {
        int s = 0, e = 0;
        cin >> s >> e;
        int sum = dp[e] - dp[s - 1];
        cout << sum << "\n";
    }
}