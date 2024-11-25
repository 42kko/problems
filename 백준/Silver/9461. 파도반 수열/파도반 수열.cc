#include <iostream>
#include <vector>
using namespace std;

long long dp[105];
int n;

int main() {
    cin >> n;

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 2;
    for (int i = 5; i < 100; i++) {
        dp[i] = dp[i - 2] + dp[i - 3];
    }
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        cout << dp[tmp - 1] << '\n';
    }
}