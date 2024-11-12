#include <iostream>
using namespace std;

/*
레벨을 난이도 순으로 배치했지만 잘못된 점수가있음
지금 점수주는것이 순서대로 배치가안되어있으니 어디를 감소시켜야할까
감소만 시킬 수 있다.
5 5 5 -> 4 5 5 -> 4 4 5 -> 3 4 5
*/

int n;
int board[105];
int cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
        }
    for (int i = n - 1; i > 0; i--) {
        while (board[i] <= board[i - 1]) {
            board[i - 1] -= 1;
            cnt++;
        }
    }
    cout << cnt;
}