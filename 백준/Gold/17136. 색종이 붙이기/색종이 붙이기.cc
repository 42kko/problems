#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;
bool board[11][11];
int counts[6] = {0,};
int ans = 1e9;

bool canUse(int x, int y, int size)
{
    if (x + size-1 >= 10 || y + size-1 >= 10) return 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (!board[x + i][y + j]) return 0;
        }
    }
    return 1;
}

void coverPaper(int x, int y, int size, int type)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            board[x + i][y + j] = type;
        }
    }
}

void recursion(int x, int y, int cnt)
{
    if (x >= 10) 
    {
        ans = min(ans, cnt);
        return;
    }
    else if (y >= 10)
    {
        recursion(x + 1, 0, cnt);
        return;
    }
    else if (board[x][y] == 0)
    {
        recursion(x, y + 1, cnt);
        return;
    }
    for (int i = 5; i > 0; i--)
    {
        if (counts[i] < 5 && canUse(x, y, i))
        {
            coverPaper(x, y, i, 0);
            counts[i]++;
            recursion(x, y + i, cnt + 1);

            coverPaper(x, y, i, 1);
            counts[i]--;
        }
    }
}

int main() 
{
    for (int i = 0; i < 10; i++) 
    {
        for (int j = 0; j < 10; j++) 
            cin >> board[i][j];
    }
    recursion(0, 0, 0);
    if (ans == 1e9) cout << "-1";
    else cout << ans;
}
