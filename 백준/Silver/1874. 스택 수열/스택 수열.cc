#include <iostream>
#include <vector>
#include <stack>
#include <sstream>
using namespace std;
// 1부터 n까지 stack에 넣엇다 뽑아서 수열만들기
// 스택에 push하는 순서는 반드시 오름차순 정렬
// 스택에 1부터 n까지 넣엇다 빼는 과정을 해서 주어진 수열을 만들수잇는가

int n, tmp, idx = 0;
int arr[100002] = { 0, };
stack<int> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    string ss;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n + 1; i++) {
        if (!s.empty() && arr[idx] == s.top()) {
            s.pop();
            idx++;
            i--;
            ss += "-\n";
        }
        else {
            s.push(i);
            if (i != n+1) ss += "+\n";
        }
    }
    if (idx == n) {
        cout << ss;
    } 
    else cout << "NO";
}

