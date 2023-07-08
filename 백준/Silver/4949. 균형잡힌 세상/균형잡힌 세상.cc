#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	while(1)
	{
		string a;
		stack<char> s;
		bool valid = true;
		getline(cin, a);
		if (a == ".")
			break;
		for (auto c : a)
		{
			if (c == '(' || c == '[')
				s.push(c);
			else if (c == ')')
			{
				if (s.empty() || s.top() != '(')
				{
					valid = false;
					break;
				}
				s.pop();
			}
			else if (c == ']')
			{
				if (s.empty() || s.top() != '[')
				{
					valid = false;
					break;
				}
				s.pop();
			}
		}
		if (!s.empty())
			valid = false;
		if (valid)
			cout << "yes\n";
		else
			cout << "no\n";
	}
}