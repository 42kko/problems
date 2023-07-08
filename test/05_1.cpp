#include <bits/stdc++.h>
using namespace std;

int main()
{
	stack<int> s;
	s.push(10);
	s.push(10);
	s.push(30);
	cout << s.size() << endl;
	if (s.empty())
		cout << "s is empty\n";
	s.pop();
	 
}	