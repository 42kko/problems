#include <bits/stdc++.h>
using namespace std;

int board[100002];
int ways[100002];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    fill(board, board + 100001, -1);
    board[n] = 0;
    ways[n] = 1;
    queue<int> q;
    q.push(n);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int nxt : {cur - 1, cur + 1, cur * 2}) {
            if (nxt < 0 || nxt > 100000) continue;
            if (board[nxt] == -1) {
                board[nxt] = board[cur] + 1;
                ways[nxt] = ways[cur];
                q.push(nxt);
            }
            else if (board[nxt] == board[cur] + 1) {
                ways[nxt] += ways[cur];
            }
        }
    }

    cout << board[k] << '\n'; 
    cout << ways[k] << '\n';   
}