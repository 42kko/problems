#include <iostream>
#include <string>
using namespace std;

int ans[10];

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    string s = to_string(a * b * c);
    for (const char e : s) {
        ans[(e - 48)]++; 
    }
    for (const int e : ans)
        cout << e << '\n';
}