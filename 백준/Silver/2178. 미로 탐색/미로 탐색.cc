#include <iostream>
#include <string>
#include <queue>
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
    for (int i = 0; i < height; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < width; j++)
        {
            board[i][j] = str[j] - '0';
        }
    }
    for (int i = 0; i < height * width; i++)
    {
        if (board[i / width][i % width] == 1 && vis[i / width][i % width] == 0)
        {
            q.push(pair<int, int>(i / width, i % width));
            vis[i / width][i % width] = 1;
        }
        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int nx = cur.first + dx[dir];
                int ny = cur.second + dy[dir];
                if (nx >= height || nx < 0 || ny >= width || ny < 0)
                    continue;
                if (vis[nx][ny] != 0 || board[nx][ny] == 0)
                    continue;
                vis[nx][ny] = vis[cur.first][cur.second] + 1;
                q.push(pair<int, int>(nx, ny));
            }
        }
    }
    cout << vis[height - 1][width - 1] << endl;
}