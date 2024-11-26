#include <iostream>
#include <vector>
using namespace std;

/*
처음 시작값 6개의 값을 하나씩 돌려가면 모든 문제 탐색
정육면체의 값을 어떻게 받아올지

다음 주사위를 올릴때 가장큰값이 올라오도록 올린다.
A F, B D, C E 가 짝을지어 바닥에 놓일수있다.
*/

int n;
vector<int> v[10005];

int opposite(int idx) {
    switch (idx) {
    case 0:
        return 5;
    case 1:
        return 3;
    case 2:
        return 4;
    case 3:
        return 1;
    case 4:
        return 2;
    case 5:
        return 0;
    }
    return -1;
}

int greedy(int nu, int bot, int top) {
    int ret = 0;
    for (int i = 0; i < 6; i++) {
        if (i == bot || i == top) continue;
        ret = max(v[nu][i], ret);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++){
            int tmp;
            cin >> tmp;
            v[i].push_back(tmp);
        }
    }

    int bot, ans = 0;
    for (int i = 0; i < 6; i++) {
        int tmp = 0;
        int top_value = v[0][opposite(i)];
        tmp += greedy(0, i, opposite(i));
        for (int j = 1; j < n; j++) {
            for (int k = 0; k < 6; k++) {
                if (v[j][k] == top_value) {
                    bot = k;
                    break;
                }
            }
            top_value = v[j][opposite(bot)];
            tmp += greedy(j, bot, opposite(bot));
        }
        ans = max(tmp, ans);
    }
    cout << ans;
}