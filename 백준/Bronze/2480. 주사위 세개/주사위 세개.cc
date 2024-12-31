#include <iostream>
using namespace std;

int main() {
    int a[3];
    cin >> a[0] >> a[1] >> a[2];

    if (a[0] == a[1] && a[1] == a[2]) {
        cout << 10000 + (a[0] * 1000);
    }
    else if (a[0] != a[1] && a[1] != a[2] && a[0] != a[2]) {
        int ans = 0;
        ans = ans > a[0] ? ans : a[0];
        ans = ans > a[1] ? ans : a[1];
        ans = ans > a[2] ? ans : a[2];
        cout << ans * 100;
    }
    else {
        if (a[0] == a[1]) cout << 1000 + (a[0] * 100);
        else if (a[1] == a[2]) cout << 1000 + (a[1] * 100);
        else cout << 1000 + (a[0] * 100);
    }
}