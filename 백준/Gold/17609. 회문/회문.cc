#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> v;
int s = 0, e = 0, t, ret, ret1;
string tmp;

int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    for (int i = 0; i < t; i++)
    {
        ret = 0;
        e = v[i].size() - 1;
        s = 0;
        while (s < e)
        {
            if (v[i][s] != v[i][e])
            {
                if (ret == 1)
                {
                    ret = 2;
                    break;
                }
                else if (v[i][s+1] == v[i][e] && e - s > 1)
                {
                    s++;
                    ret = 1;
                }
                else if (v[i][s] == v[i][e-1] && e - s > 1)
                {
                    ret = 1;
                    e--;
                }
                else if (s + 1 == e)
                {
                    ret = 1;
                    break;
                }
                else
                {
                    ret = 2;
                    break;
                }
            }
            e--;
            s++;
        }
        ret1 = 0;
        e = v[i].size() - 1;
        s = 0;
        while (s < e)
        {
            if (v[i][s] != v[i][e])
            {
                if (ret1 == 1)
                {
                    ret1 = 2;
                    break;
                }
                else if (v[i][s] == v[i][e-1] && e - s > 1)
                {
                    ret1 = 1;
                    e--;
                }
                else if (v[i][s+1] == v[i][e] && e - s > 1)
                {
                    s++;
                    ret1 = 1;
                }
                else
                {
                    ret1 = 2;
                    break;
                }
            }
            e--;
            s++;
        }
        ret > ret1 ? ret = ret1 : 0;
        cout << ret << "\n";
    }
}