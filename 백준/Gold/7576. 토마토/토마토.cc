#include <iostream>
#include <string>
#include <queue>
using namespace std;

int board[1002][1002];
int vis[1002][1002];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int height, width;
    cin >> width >> height;
    queue<pair<int, int> > q;
    for (int i = 0; i < height * width; i++)
        cin >> board[i / width][i % width];
    int day = 0;
    for (int i = 0; i < height * width; i++)
    {
        if (board[i / width][i % width] == 1)
            q.push(pair<int, int>(i / width, i % width));
    }
    while(!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || nx >= height || ny < 0 || ny >= width)
                continue;
            if (board[nx][ny] != 0)
                continue;
            board[nx][ny] = board[cur.first][cur.second] + 1;
            q.push(pair<int, int>(nx, ny));
        }
    }
    for (int i = 0; i < height * width; i++)
    {
        if (board[i / width][i % width] == 0)
        {
            cout << "-1" << endl;
            return 0;
        }
        if (day < board[i / width][i % width])
            day = board[i / width][i % width];
    }
    cout << day - 1 << endl;
    return 0;
}