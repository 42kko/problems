#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int budget[10005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    int max_budget = 0;
    for (int i = 0; i < n; i++) {
        cin >> budget[i];
        max_budget = max(max_budget, budget[i]);
    }
    cin >> m;

    int left = 0, right = max_budget;
    int ans = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        long long tmp = 0;
        for (int i = 0; i < n; i++) {
            tmp += min(budget[i], mid);
        }

        if (tmp <= m) {
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << ans;
    return 0;
}