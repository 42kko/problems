#include <iostream>
using namespace std;
/*
daldialgo, daldidan

d da dal dald daldi daldial daldialg daldialgo 
daldialgodaldialgo
daldialgodaldialgodaldia
daldialgodaldialgodaldian

4
daldialgo - 8
daldialgodaldialgo - 9
daldialgodaldialgodaldialgodaldialgo - 10

go gogo gogogo

*/

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