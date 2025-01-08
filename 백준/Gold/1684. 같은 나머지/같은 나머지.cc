#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
입력으로 들어오는 수는 어떤 정수 D로 나누었을때 나머지가 같다.
D중 가장 큰 D를 구하시오
*/

int n;
int arr[1005];
int ans;
vector<int> v;

int GCD(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    cin >> n;
    cin >> arr[0];
    for (int i = 1; i < n; i++) {
        cin >> arr[i];
        v.push_back(arr[i] - arr[i - 1]);
    }
   
    ans = v[0];
    for (int i = 1; i < v.size(); i++) {
        ans = GCD(ans, v[i]);
    }
    cout << abs(ans);
}