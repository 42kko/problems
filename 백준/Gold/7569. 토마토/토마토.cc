#include <iostream>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

int board[102][102][102];
int vis[102][102][102];
int dx[6] = {0, 0, -1, 1, 0, 0};
int dy[6] = {-1, 1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int width, height, depth;
    cin >> width >> height >> depth;
    for (int i = 0; i < width * height * depth; i++)
    {
        cin >> board[i / (width * height)][(i / width) % height][i % width];
    }
    queue<tuple<int, int, int> > q;
    for (int i = 0; i < width * height * depth; i++)
    {
        if (board[i / (width * height)][(i / width) % height][i % width] == 1)
            q.push(tuple<int, int, int>(i / (width * height), (i / width) % height, i % width));
    }
    while (!q.empty())
    {
        tuple<int, int, int> cur = q.front();
        q.pop();
        for (int dir = 0; dir < 6; dir++)
        {
            int nx = get<1>(cur) + dx[dir];
            int ny = get<2>(cur) + dy[dir];
            int nz = get<0>(cur) + dz[dir];
            if (nx < 0 || nx >= height || ny < 0 || ny >= width || nz < 0 || nz >= depth)
                continue;
            if (board[nz][nx][ny] != 0)
                continue;
            board[nz][nx][ny] = board[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            q.push(tuple<int, int, int>(nz, nx, ny));
        }
    }
    int day = 0;
    for (int i = 0; i < width * height * depth; i++)
    {
        if (board[i / (width * height)][(i / width) % height][i % width] == 0)
        {
            cout << "-1" << endl;
            return 0;
        }
        else if (board[i / (width * height)][(i / width) % height][i % width] > day)
            day = board[i / (width * height)][(i / width) % height][i % width];
    }
    cout << day - 1 << endl;
}