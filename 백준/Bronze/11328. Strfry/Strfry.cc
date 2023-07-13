#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int cnt;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str1, str2;
    int n;
    cin >> n;
    bool tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> str1 >> str2;
        tmp = false;
        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());
        for (int j = 0; j < str1.size(); j++)
        {
            if (str1[j] != str2[j])
            {
                tmp = true;
                    break;
            }
            if (tmp)
                break;
        }
        if (!tmp)
            cout << "Possible" << '\n';
        else
            cout << "Impossible" << '\n';
    }
}