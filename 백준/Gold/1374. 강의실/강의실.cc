#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
2 14
3 8
6 20
6 27
7 13
12 18
15 21
20 25

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
priority_queue<int, vector<int>, greater<int> > pq;

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
        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    });

    pq.push(v[0].second);
    for (int i = 1; i < n; i++) {
        if (v[i].first >= pq.top())
            pq.pop();
        pq.push(v[i].second);
    }
    cout << pq.size();
}