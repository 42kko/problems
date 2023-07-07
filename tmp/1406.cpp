#include<bits/stdc++.h>
using namespace std;

bool isLower(string s)
{
	for (char c :  s)
	{
		if (!islower(c))
			return false;
	}
	return true;
}
// todo: 
// fixme: 
int main()
{
	string s;
	int cnt;
	cin >> s >> cnt;
	if (s.size() > 100000 || cnt > 500000 || cnt < 1 || !isLower(s))
		return 1;
	
	for (int i = 0; i < cnt; i++)
	{

	}
}