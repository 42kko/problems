#include <iostream>
using namespace std;
bool cols[25];
bool left_diag[50];
bool right_diag[50];
int n;
int cnt;

void func(int row)
{
    if (row == n)
    {
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (cols[i] || left_diag[i + row] || right_diag[row - i + n]) continue;
        cols[i] = 1;
        left_diag[i + row] = 1;
        right_diag[row - i + n] = 1;
        func(row + 1);
        cols[i] = 0;
        left_diag[i + row] = 0;
        right_diag[row - i + n] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    func(0);
    cout << cnt;
}