#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// int func4(int n)
// {
//     int idx = 0;
//     while (n)
//     {
//         n /= 2;
//         idx++;
//     }
//     int ret = 1;
//     for (int i = 0; i < idx - 1; i++)
//     {
//         ret *= 2;
//     }
//     return (ret);
// }

int func4(int n)
{
    int i = 1;
    while (i * 2 <= n)
        i *= 2;
    return (i);
}

int main()
{
    int ret = func4(97615282);
    cout << ret << endl;
}