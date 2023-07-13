#include <iostream>
using namespace std;

int func(int n, int height, int width)
{
    if (n == 0)
        return 0;
    int half = 1 << (n - 1);
    if (height < half && width < half)
        return func(n - 1, height, width);
    if (height < half && width >= half)
        return half * half + func(n-1, height, width-half);
    if (height >= half && width < half)
        return half * half * 2 + func(n-1, height-half, width);
    return half * half * 3 + func(n-1, height-half, width-half);
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, height, width;
    cin >> n >> height >> width;
    cout << func(n, height, width);
}