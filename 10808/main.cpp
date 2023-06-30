#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    int arr[26];
    memset(arr, 0, sizeof(arr));
    string str;
    getline(cin, str);
    for(int i = 0; i < str.size(); i++)
    {
        arr[str[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
        cout << arr[i] << ' ';
}

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