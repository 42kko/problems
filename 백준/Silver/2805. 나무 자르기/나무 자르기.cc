#include <iostream>
#include <vector>
using namespace std;

/*
필요한 나무 m미터를 짜를수있는 최대의 높이
즉, 절단기를 최대로 높여 최소한의 나무만을 짤라 m을 만족해야한다
*/

long long n, m;
vector<long long> tree;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        long long tmp;
        cin >> tmp;
        tree.push_back(tmp);
    }

    long long left = 0, right = 1e9;
    long long ans = 0;
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long tmp = 0; // 얻은나무
        for (const long long e : tree) {
            if (e > mid) //잘라서 얻은나무
                tmp += e - mid;
        }
        if (tmp >= m) { //나무를 많이자른경우
            ans = mid;
            left = mid + 1;
        }
        else if (tmp < m) {
            right = mid - 1;
        }
    } 
    cout << ans;
}