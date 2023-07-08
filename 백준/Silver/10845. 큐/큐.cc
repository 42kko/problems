#include <bits/stdc++.h>
using namespace std;

int dat[100000];
int head = 0;
int tail = 0;

void push(int i)
{
	dat[tail++] = i;
}

int pop()
{
	if (head == tail)
		return (-1);
	return (dat[head++]);
}

int size()
{
	return (tail - head);
}

bool empty()
{
	return (tail - head == 0 ? true : false);
}

int front()
{
	if (head == tail)
		return (-1);
	return (dat[head]);
}

int back()
{
	if (head == tail)
		return (-1);
	return (dat[tail - 1]);
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
		else if (str == "front")
			cout << front() << endl;
		else if (str == "back")
			cout << back() << endl;
	}
	return (0);
}