#include <iostream>
using namespace std;

/*
마지막 징검다리는 꼭 밟아야한다.
첫번째는 아무곳이나 밟을수있고
두번째 점프부터는 이전 점프거리보다 1 이상 더 뛰어야한다.
가장 많이 밟고 가고싶어한다.

즉 n번째에 도달할 수 있는 최대 점프수를 찾는것
n은 10^16 이므로 최소범위를 찾지않으면 시간초과가 날것
*/

long long t;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> t;
    long long n;
    for (int i = 0; i < t; i++) {
        cin >> n;

        long long left = 0, right = 1e9, ans = 0;
        while (left <= right) {
            long long mid = (left + right) / 2;
            if (((mid * (mid + 1)) / 2) <= n) {
                ans = mid;
                left = mid + 1;   
            }
            else
                right = mid - 1;
        }
        cout << ans << '\n';
    }
}