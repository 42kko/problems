#include <bits/stdc++.h>
using namespace std;

int dat[100000];
int pos = 0;

void push(int i)
{
	dat[pos++] = i;
}

int pop()
{
	if (pos == 0)
		return (-1);
	return (dat[--pos]);
}

int size()
{
	return (pos);
}

bool empty()
{
	return (pos == 0 ? true : false);
}

int top()
{
	if (pos == 0)
		return (-1);
	return (dat[pos - 1]);
}

int main()
{
	int cnt;
	cin >> cnt;
	for(int i = 0; i < cnt; i++)
	{
		string str;
		int a;
		cin >> str;
		if (str == "push")
		{
			cin >> a;
			push(a);
		}
		else if (str == "pop")
			cout << pop() << endl;
		else if (str == "size")
			cout << size() << endl;
		else if (str == "empty")
			cout << empty() << endl;
		else if (str == "top")
			cout << top() << endl;
	}
	return (0);
}