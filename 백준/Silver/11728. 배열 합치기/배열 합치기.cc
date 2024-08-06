#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, m, temp, ai = 0, bi = 0;
vector <int> a, b, ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }
    for(int i = 0; i < m; i++)
    {
        cin >> temp;
        b.push_back(temp);
    }
    for(int i = 0; i < a.size() + b.size(); i++)
    {
        if (ai >= n)
        {
            ans.push_back(b[bi]);
            bi++;
        }
        else if (bi >= m)
        {
            ans.push_back(a[ai]);
            ai++;
        }
        else if (a[ai] < b[bi])
        {
            ans.push_back(a[ai]);
            ai++;
        }
        else
        {
            ans.push_back(b[bi]);
            bi++;
        }
    }
    for(const int &element : ans)
        cout << element<< " ";
}