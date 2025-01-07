#include <iostream>
using namespace std;

int n;
int dp[10005];

int main () {
    cin >> n;
    dp[0] = 2;
    dp[1] = 4;
    for (int i = 2; i < n; i++) {
        dp[i] = dp[i - 1] + 2;
        if (dp[i] > n)
            dp[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        cout << dp[i] << '\n';
    }
}