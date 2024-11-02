#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int c1 = 0;
int c2 = 0;
int dp0[45];
int dp1[45];
int t;
int n;

int main() {
    cin >> t;
    dp0[0] = 1;
    dp0[1] = 0;
    dp1[0] = 0;
    dp1[1] = 1;
    for (int i = 2; i <= 40; i++) {
        dp0[i] = dp0[i - 1] + dp0[i - 2];
        dp1[i] = dp1[i - 1] + dp1[i - 2];
    }    
    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << dp0[n] << ' ' << dp1[n] << '\n';
    }
}