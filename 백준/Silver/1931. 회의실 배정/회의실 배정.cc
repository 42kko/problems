#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
하나의 회의실 n개의 회의
시작과 끝나는 시간은 2^31
*/

int n;
vector<pair<long long, long long> > table;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        long long tmp, tmp1;
        cin >> tmp >> tmp1;
        table.push_back({tmp, tmp1});
    }
    sort(table.begin(), table.end(), [](const pair<long long, long long> &a, const pair<long long, long long> &b){
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    });

    long long ans = 0;
    long long cur = 0;
    for (const auto e : table) {
        if (e.first >= cur) {
            cur = e.second;
            ans++;
        }
    }
    cout << ans;
}