#include <iostream>
#include <math.h>
using namespace std;

/*
퍼센테이지가 바뀌는 로직을 작성하면될듯.
게임횟수와, 이긴게임이 들어올때 -> 초기값의 퍼센트
만약 100이면 -1 리턴
게임횟수와 이긴게임을 1씩더해 퍼센트가 바뀌는 최솟값출력
*/

double x, y;
long long initial;

bool change(long long mid, long long initial) {
    long long newPercent = ((y + mid) * 100) / (x + mid);
    return newPercent > initial;
}

int main() {
    cin >> x >> y;

    initial = (y * 100) / x;
    if (initial >= 99) {
        cout << -1;
        return 0;
    }

    long long left = 1, right = 1e9, result = -1;
    while (left <= right) {
        long long mid = (left + right) / 2;
        if (change(mid, initial)) {
            result = mid;  // 최소 게임 횟수 갱신
            right = mid - 1;  // 더 작은 범위를 탐색
        } else {
            left = mid + 1;  // 더 큰 범위를 탐색
        }
    }

    cout << result << endl;
    return 0;
}