#include <iostream>
#include <vector>
using namespace std;

int n, s, tmp, b = 0, e = 0;
vector<int> v;
int ret = __INT_MAX__;

int main()
{
    cin >> n >> s;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    tmp = v[b];
    while (e < n)
    {
        if (e < b) e = b;
        if (tmp >= s)
        {
            ret > e - b ? ret = e - b : 0;
            tmp -= v[b];
            b++;
        }
        else
        {
            e++;
            tmp += v[e];
        }
    }
    if (ret == __INT_MAX__) cout << "0";
    else cout << ret + 1;
}