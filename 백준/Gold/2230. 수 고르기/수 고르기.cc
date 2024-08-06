#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, tmp, s = 0, e = 0;
vector<int> v;
int ret = 2147483647;

int main ()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    while(e < v.size())
    {
        if (ret == m) break;
        if (v[e] - v[s] >= m)
        {
            ret > v[e] - v[s] ? ret = v[e] - v[s] : 0;
            s++;
        }
        else
            e++;
    }

    cout << ret;
}