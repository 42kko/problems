#include <iostream>
#include <algorithm>

using namespace std;

int board[10][10];
int used[6] = {0};  // 각 크기별 색종이 사용 개수
int answer = 1e9;   // 초기 정답을 매우 큰 값으로 설정

bool canAttach(int x, int y, int size) {
    if (x + size > 10 || y + size > 10) return false; // 범위를 넘으면 불가능
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[x + i][y + j] == 0) return false;
        }
    }
    return true;
}

void attach(int x, int y, int size, int state) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[x + i][y + j] = state;
        }
    }
}

void dfs(int x, int y, int cnt) {
    if (x >= 10) {  // 모든 행을 다 탐색한 경우
        answer = min(answer, cnt);
        return;
    }

    if (y >= 10) {  // 다음 행으로 넘어가기
        dfs(x + 1, 0, cnt);
        return;
    }

    if (board[x][y] == 0) {  // 현재 위치가 이미 덮여있는 경우
        dfs(x, y + 1, cnt);
        return;
    }

    for (int size = 5; size >= 1; size--) {
        if (used[size] < 5 && canAttach(x, y, size)) {
            attach(x, y, size, 0);  // 색종이로 덮기
            used[size]++;
            dfs(x, y + size, cnt + 1);  // 다음 위치로 이동
            attach(x, y, size, 1);  // 색종이 제거
            used[size]--;
        }
    }
}

int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> board[i][j];
        }
    }

    dfs(0, 0, 0);  // DFS 탐색 시작

    if (answer == 1e9) {
        cout << -1 << endl;  // 불가능한 경우
    } else {
        cout << answer << endl;
    }

    return 0;
}