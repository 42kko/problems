#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, tmp;
//m개의 수열
vector<int> v;
vector<int> check(10000, 0);

void print_and_clear(vector<int> &ans)
{
    for (auto it = ans.begin(); it != ans.end(); ++it)
    {
        if (it != ans.begin())
        {
            printf(" ");
        }
        printf("%i", *it);
    }
    printf("\n");
    return;
}

void recursion(vector<int> ans, int idx)
{
    if (idx == m)
    {
        print_and_clear(ans);
        return;
    }
    for(int i = 0; i < n; i++)
    {
        if (check[v[i]] == 0)
        {
            check[v[i]] = 1;
            ans[idx] = v[i];
            recursion(ans, idx +1);
            check[v[i]] = 0;
        }
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
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    recursion(ans, idx);
}