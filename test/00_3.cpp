#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool fun3(int n)
{
    for (int i = 0; i < n /2; i++)
    {
        if (i * i == n)
            return true;
    }
    return false;
}

int main()
{
    cout << (fun3(25) ? "true" : "false") << endl;
}