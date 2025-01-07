#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define Y 0
#define X 1
 
int n, k;
int ans[10][2];

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int y;
        bool gender;
        cin >> gender >> y;
        ans[y][gender]++;
    }
    int ret = 0;
    for (int i = 1; i < 7; i++) {
        ret += ans[i][0] / k;
        if (ans[i][0] % k != 0) ret++;
        ret += ans[i][1] / k;
        if (ans[i][1] % k != 0) ret++;

    }
    cout << ret;
}