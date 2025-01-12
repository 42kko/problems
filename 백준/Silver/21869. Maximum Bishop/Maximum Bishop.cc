#include <iostream>
using namespace std;

int n;

int main() {
	cin >> n;
	int ans = n + (n - 2);
	if (ans <= 0) ans = 1;
	cout << ans << '\n';
	for (int i = 1; i <= n; i++) {
		cout << 1 << ' ' << i << '\n';
	}
	for (int i = 2; i < n; i++) {
		cout << n << ' ' << i << '\n';
	}
}