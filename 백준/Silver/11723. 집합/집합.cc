#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

*/
vector<int> s;
bool check[25] = {
    0,
};
int m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> m;
    s.resize(25);
    for (int i = 0; i < m; i++)
    {
        string cmd;
        int num;
        cin >> cmd;
        if (cmd != "all" && cmd != "empty")
            cin >> num;
        if (cmd == "add" && !check[num])
        {
            s.push_back(num);
            check[num] = true;
        }
        else if (cmd == "remove" && check[num])
        {
            s.erase(find(s.begin(), s.end(), num));
            check[num] = false;
        }
        else if (cmd == "check")
        {
            if (check[num])
                cout << "1" << '\n';
            else
                cout << "0" << '\n';
        }
        else if (cmd == "toggle")
        {
            if (!check[num])
            {
                s.push_back(num);
                check[num] = true;
            }
            else
            {
                s.erase(find(s.begin(), s.end(), num));
                check[num] = false;
            }
        }
        else if (cmd == "all")
        {
            for (int j = 0; j < 20; j++)
            {
                s[j] = j + 1;
                check[j + 1] = true;
            }
        }
        else if (cmd == "empty")
        {
            for (int j = 0; j < 20; j++)
            {
                s[j] = 0;
                check[j + 1] = false;
            }
        }
    }
}