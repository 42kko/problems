#include<bits/stdc++.h>
using namespace std;

int board[1000002];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	fill(board, board+1000001, -1);
	board[n] = 0;
	queue<int> q;
	q.push(n);
	while (board[k] == -1)
	{
		int cur = q.front();
		q.pop();
		for (int nxt : {cur - 1, cur + 1, cur * 2})
		{
			if (nxt < 0 || nxt > 100000)
				continue;
			if (board[nxt] != -1)
				continue;
			board[nxt] = board[cur] + 1;
			q.push(nxt);
		}
	}
	cout << board[k];
}