#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m, tmp;
vector<int> board;

void recursion(int idx, vector<int> ans, vector<int> check)
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
        if (check[board[i]] == 0)
        {
            check[board[i]] = 1;
            ans[idx] = board[i];
            recursion(idx + 1, ans, check);
        }
    }
}

int main() 
{
    int idx = 0;
    cin >> n >> m;
    vector<int> ans(m);
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        board.push_back(tmp);
    }
    vector<int> check(10000, 0);
    sort(board.begin(), board.end());
    recursion(idx, ans, check);
}