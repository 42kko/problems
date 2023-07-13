#include <iostream>
#include <string>
using namespace std;
int cnt;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str1, str2;
    int n;
    cin >> n;
    bool tmp = false;
    for (int i = 0; i < n; i++)
    {
        cin >> str1 >> str2;
        tmp = false;
        for (int j = 0; j < str1.size(); j++)
        {
            for (int k = 0; k < str2.size(); k++)
            {
                if (str1[j] != str2[k])
                {
                    cout << "Impossible" << '\n';
                    tmp = true;
                    break;
                }
            }
            if (tmp)
                break;
        }
        if (!tmp)
            cout << "Possible" << '\n';
    }
}