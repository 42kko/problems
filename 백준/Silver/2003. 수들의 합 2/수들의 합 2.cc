#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long m;
int arr[10005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int left = 0, right = 0;
    long long sum = 0;
    int ans = 0;
    while (right <= n) {
        if (sum == m)
            ans++;
        if (sum < m) {
            sum += arr[right];
            right++;
        }
        else {
            sum -= arr[left];
            left++;
        }
    }
    cout << ans;
}