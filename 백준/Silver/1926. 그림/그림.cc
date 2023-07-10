#include <bits/stdc++.h>
using namespace std;

int board[502][502];
int vis[502][502];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int, int> > q;
    int width, height;
    cin >> height >> width;
    int cnt = 0;
    int area = 0;
    for (int i = 0; i < height * width; i++)
        cin >> board[i / width][i % width];
    for (int i = 0; i < height * width; i++)
    {
        int tmp = 0;
        if (board[i / width][i % width] == 1 && vis[i / width][i % width] != 1)
        {
            q.push(pair<int, int>(i / width, i % width));
            vis[i / width][i % width] = 1;
            tmp++;
            cnt++;
        }
        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx < 0 || nx >= height || ny < 0 || ny >= width)
                    continue;
                if (vis[nx][ny] || board[nx][ny] != 1)
                    continue;
                vis[nx][ny] = 1;
                q.push(pair<int, int>(nx, ny));
                tmp++;
            }
        }
        if (area < tmp)
            area = tmp;
    }
    area = cnt == 0 ? 0 : area;
    cout << cnt << endl;
    cout << area << endl;
}
