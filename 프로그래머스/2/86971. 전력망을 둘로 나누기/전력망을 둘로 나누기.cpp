#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
트리형태의 송전탑

트리를 분할해 2개만들고싶음
두개의 트리를 최대한 비슷하게

이진트리 아님!

트리를 분할한 이후 두개 트리의 차이를 출력

균형트리도아니고 이진트리도아니니, 하나하나 끊어야할듯
*/

int ans;
vector<int> v[105];
bool vist[105];

int recursion(int cur) {
    int count = 1;
    vist[cur] = true;
    for (const auto e : v[cur]) {
        if (vist[e]) continue;
        count += recursion(e);
    }
    return count;
}

int solution(int n, vector<vector<int>> wires) {
    for (const auto e : wires) {
        v[e[0]].push_back(e[1]);
        v[e[1]].push_back(e[0]);
    }

    ans = n;
    for (const auto e : wires) {
        v[e[0]].erase(remove(v[e[0]].begin(), v[e[0]].end(), e[1]), v[e[0]].end());
        v[e[1]].erase(remove(v[e[1]].begin(), v[e[1]].end(), e[0]), v[e[1]].end());
        fill(vist, (vist + 105), 0);
        vist[1] = true;
        int tmp_size = recursion(1);

        ans = min(ans, abs(tmp_size - abs(tmp_size - n)));
        v[e[0]].push_back(e[1]);
        v[e[1]].push_back(e[0]);
    }
    return ans;
}