#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> sensors;
vector<int> diffs;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    sensors.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> sensors[i];
    }

    sort(sensors.begin(), sensors.end());

    for (int i = 1; i < n; i++) {
        diffs.push_back(sensors[i] - sensors[i - 1]);
    }

    sort(diffs.begin(), diffs.end(), greater<int>());

    int ans = 0;
    // 가장 큰 K-1개의 차이를 제거
    for (int i = k - 1; i < diffs.size(); i++) {
        ans += diffs[i];
    }

    cout << ans << '\n';
    return 0;
}