#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, tmp;
// vector<int> check(10000, 0);
vector<int> board;

void recursion(vector<int>ans, int idx)
{
    if (idx == m)
    {
        for (const int e : ans)
            printf("%i ", e);
        printf("\n");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        // if (ans[idx] <= board[i])
        if (idx != 0 && ans[idx - 1] > board[i])
            continue;
        ans[idx] = board[i];
        recursion(ans, idx + 1);
    }
}

int main()
{
    int idx = 0;
    cin >> n >> m;
    vector<int> ans(m, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        board.push_back(tmp);
    }
    sort(board.begin(), board.end());
    recursion(ans, idx);
}