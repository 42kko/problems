#include <iostream>
using namespace std;

int n, ans;

int main() {
    cin >> n;
    while (n % 5 != 0) {
        n -= 2;
        ans++;
    }
    if (n == 0)
        cout << ans;
    else if (n < 0)
        cout << "-1";
    else 
        cout << ans + (n / 5);
}