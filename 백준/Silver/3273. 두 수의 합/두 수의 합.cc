#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int x;
vector <int> v;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    cin >> x;
    sort(v.begin(), v.end());

    int ans = 0, left = 0, right = n - 1;
    while(left < right) {
        int mid = v[left] + v[right];

        if (mid == x) {
            ans++;
            left++;
            right--;
        } 
        else if (mid < x)
            left++;
        else
            right--;
    }
    cout << ans;
}