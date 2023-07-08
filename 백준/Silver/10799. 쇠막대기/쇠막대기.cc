#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string str;
	cin >> str;
	stack<char> s;
	int ans = 0;
	int cnt = 0;
	for (auto c : str)
	{
		s.push(c);
	}
	
	while (!s.empty())
	{
		char c = s.top();
		s.pop();
		switch (c)
		{
		case ')':
			if (s.top() == ')')
			{
				cnt++;
			}
			else if (s.top() == '(')
			{
				ans += cnt;
				s.pop();
			}
			break;
		case '(':
			ans++;
			cnt--;
			break;
		default:
			break;
		}
	}
	cout << ans <<endl;
}