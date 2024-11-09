#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
모든사람이 기다린 시간이 최소가 될때
1000이니까 백트래킹은 불가능
수학적으로 접근해야할것같은데
*/

vector<int> v;
int n;
int dp[1005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());

    dp[0] = v[0];
    long long ans = dp[0];
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1] + v[i];
        ans += dp[i];
    }
    cout << ans;
}