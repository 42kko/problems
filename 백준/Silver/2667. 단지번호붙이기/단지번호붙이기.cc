#include <bits/stdc++.h>
using namespace std;

int board[27][27];
int vis[27][27];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string tmp;
		tmp.clear();
		cin >> tmp;
		for (int j = 0; j < n; j++)
		{
			board[i][j] = tmp[j] - '0';
		}
	}
	int cnt = 0;
	vector<int> area;
	int tmp;
	queue<pair<int,int> > q;
	for (int i = 0; i < n * n; i++)
	{
		tmp = 0;
		if (vis[i / n][i % n] == 0 && board[i / n][i % n] == 1)
		{
			q.push(pair<int,int>{i / n, i % n});
			cnt++;
			tmp++;
			vis[i / n][i % n] = 1;
		}
		while (!q.empty())
		{
			pair<int,int> cur = q.front();
			q.pop();
			for(int dir = 0; dir < 4; dir++)
			{
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n)
					continue;
				if (vis[nx][ny] == 1 || board[nx][ny] != 1)
					continue;
				q.push(pair<int,int>{nx,ny});
				vis[nx][ny] = 1;
				tmp++;
			}
		}
		tmp == 0 ? void() : area.push_back(tmp);
	}
	cout << cnt << "\n";
	sort(area.begin(), area.end());
	for(int i = 0; i < area.size(); i++)
		cout << area[i] << "\n";
    return 0;
}
