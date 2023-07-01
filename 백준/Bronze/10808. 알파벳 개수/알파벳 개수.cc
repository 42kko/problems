#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    string s;
    cin >> s;
    for(char a = 'a'; a <= 'z'; a++)
    {
        int cnt = 0;
        for (auto c : s)
            if (a == c)
                cnt++;
        cout << cnt << ' ';
    }
}