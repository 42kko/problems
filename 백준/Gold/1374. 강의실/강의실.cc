#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
3 8
7 13
2 14
12 18
6 20
15 21
20 25
6 27
*/

int n;
vector<pair<int, int> > v;
vector<int> ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp, tmp1;
        cin >> tmp >> tmp >> tmp1;
        v.push_back({tmp, tmp1});
    }
    sort(v.begin(), v.end(), [](pair<int, int> &a, pair<int, int> &b) {
        // if (a.second == b.second)
        //     return a.first < b.first;
        // return a.second < b.second;

        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    });

    ans.push_back(0);
    bool flag = 0;
    for (const auto &e : v) {
        flag = 0;
        for (int i = 0; i < ans.size(); i++) {
            if (e.first >= ans[i]) {
                ans[i] = e.second;
                flag = 1;
                break;
            }
        }
        if (!flag)
            ans.push_back(e.second);
    }
    cout << ans.size();
}