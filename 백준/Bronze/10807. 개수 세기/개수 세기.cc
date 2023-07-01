#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, x, a[101];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> x;
    int cont = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
            cont++;
    }
    cout << cont << endl;
}