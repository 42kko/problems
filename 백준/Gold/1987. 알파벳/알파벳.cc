#include <iostream>
#include <vector>
using namespace std;

int board[21][21];
bool vis[21][21];
bool check[26];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int r, c;
char tmp;
// 1,1 -> 1,2 2,1

int ret = 0;
void recursion(int count, int cur_x, int cur_y)
{
    if (ret < count) 
    {
        ret = count;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = cur_x + dx[i];
        int ny = cur_y + dy[i];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
        if (check[board[nx][ny] - 65] == 1 || vis[nx][ny]) continue;
        check[board[nx][ny] - 65] = 1;
        vis[nx][ny] = 1;
        recursion(count + 1, nx, ny);
        check[board[nx][ny] - 65] = 0;
        vis[nx][ny] = 0;
    }
}

int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> tmp;
            board[i][j] = tmp;
        }
    }
    check[(board[0][0] - 65)] = 1;
    recursion(1, 0, 0);
    cout << ret;
}