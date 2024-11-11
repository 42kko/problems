#include <iostream>
#include <vector>
using namespace std;

/*
A S D F G
abcdefghijklmnopqrstuvwxyz
맨오른쪽과 왼쪽을 비교해 작은애를 놓는다
*/
char arr[1005];
int t, n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<char> v;
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
            if (!v.size())
                v.push_back(arr[j]);
            else if (arr[j] <= v[0])
                v.insert(v.begin(), arr[j]);
            else
                v.push_back(arr[j]);
        }
        for (const char c : v) {
            cout << c;
        }
        cout << "\n";
    }
}