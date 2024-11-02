#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int n, m;
unordered_set<string> v1;
vector<string> ans;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        v1.insert(tmp);
    }
    for (int i = 0; i < m; i++) {
        string tmp;
        cin >> tmp;
        if (v1.find(tmp) != v1.end()) {
            ans.push_back(tmp);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (const auto e : ans) {
        cout << e << "\n";
    }
}