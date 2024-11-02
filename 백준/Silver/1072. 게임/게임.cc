#include <iostream>
#include <math.h>
using namespace std;

/*
퍼센테이지가 바뀌는 로직을 작성하면될듯.
게임횟수와, 이긴게임이 들어올때 -> 초기값의 퍼센트
만약 100이면 -1 리턴
게임횟수와 이긴게임을 1씩더해 퍼센트가 바뀌는 최솟값출력
*/

long long x, y;
long long initial;

bool change(long long mid) {
    long long newInit = ((y + mid) * 100) / (x + mid);
    return !(newInit == initial); //1이면 변화가있다
}

int main() {
    cin >> x >> y;

    initial = (y * 100) / x;
    if (initial >= 99) {
        cout << -1;
        return 0;
    }

    long long left = 1, right = 1e9, ans = -1;
    while (left <= right) {
        long long mid = (left + right) / 2;
        if (change(mid)) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << ans;
    return 0;
}