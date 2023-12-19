#include <bits/stdc++.h>
using namespace std;

vector<int> board[102];
int vis[102];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 0;
    int cnt_in = 0;
    int ret = 0;
    cin >> cnt >> cnt_in;
    for (int i = 0; i < cnt_in; i++)
    {
        int a, b;
        cin >> a >> b;
        board[a].push_back(b);
        board[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while (!q.empty())
    {
        int cur =  q.front();
		q.pop();
		for (int i = 0; i < board[cur].size(); i++)
		{
			if (vis[board[cur][i]] == 0)
			{
				q.push(board[cur][i]);
				vis[board[cur][i]] = 1;
				ret++;
			}
		}
    }
    cout << ret;
    return 0;
}
