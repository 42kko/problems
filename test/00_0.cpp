#include <iostream>
using namespace std;

int main()
{
    int a;
    long result = 0;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
        {
            result += i;
        }
    }
    cout << result << endl;
    return (0);
}