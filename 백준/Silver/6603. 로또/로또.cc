#include<iostream>
#include<vector>
using namespace std;

int k, s = 6, tmp;
vector< vector<int> > v;
int check[49] = { 0,};

//이전보다 숫자는 작아야하고, ans[0] >= v[a][k - 5 - 1]

void recursion(vector<int> ans, int idx, int a)
{
    if (idx == s)
    {
        for (const int e : ans)
            printf("%i ", e);
        printf("\n");
        return;
    }
    for (int i = 0; i < v[a].size(); i++)
    {
        if (check[v[a][i]] == 0)
        {
            if (idx != 0 && ans[idx - 1] > v[a][i])
                continue;
            check[v[a][i]] = 1;
            ans[idx] = v[a][i];
            if (ans[0] >= v[a][v[a].size() - 5])
                return;
            recursion(ans, idx + 1, a);
            check[v[a][i]] = 0;
        }
    }
}

int main()
{
    int a = 0;
    int idx = 0;
    while(1)
    {
        cin >> k;
        for (int i = 0; i < k; i++)
        {
            cin >> tmp;
            if (v.size() <= a)
                v.resize(a + 1);
            v[a].push_back(tmp);
        }
        if (k == 0)
            break;
        a++;
    }
    a = 0;
    for (int i = 0; i < v.size(); i++)
    {
        vector<int> ans(s, 0);
        recursion(ans, idx, a);
        a++;
        printf("\n");
        for (int i = 0; i < 49; i++)
            check[i] = 0;
    }
}

