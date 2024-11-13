#include <iostream>
using namespace std;

int n;
int ans;
int main() {
    cin >> n;

    ans = 8;
    int tmp = 0;
    while(n >= 2) {
        n /= 2;
        tmp++;
    }
    ans += tmp + 2;
    cout << ans;
}