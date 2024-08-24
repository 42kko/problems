#include <iostream>
using namespace std;
bool used1[17];
bool used2[17];
bool used3[17];
int n;
int cnt;

void func(int cur)
{
    if (cur == n)
    {
        cnt++;
        return ;
    }
    for (int i = 0; i < n; i++)
    {
        if (used1[i] || used2[i + cur] || used3[cur - i + n - 1])
            continue;
        used1[i] = 1;
        used2[i + cur] = 1;
        used3[cur - i + n - 1] = 1;
        func(cur + 1);
        used1[i] = 0;
        used2[i + cur] = 0;
        used3[cur - i + n - 1] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    func(0);
    cout << cnt;
}