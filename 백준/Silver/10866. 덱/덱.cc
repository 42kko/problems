#include <bits/stdc++.h>
using namespace std;

const int mx = 100000;
int dat[mx * 2 + 1];
int head = mx;
int tail = mx;

void push_front(int i)
{
	dat[--head] = i;
}

void push_back(int i)
{
	dat[tail++] = i;
}

int pop_front()
{
	if (head == tail)
		return (-1);
	return (dat[head++]);
}

int pop_back()
{
	if (head == tail)
		return (-1);
	return (dat[--tail]);
}

bool empty()
{
	return (tail - head == 0 ? true : false);
}

int size()
{
	return (tail - head);
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
		if (str == "push_front")
		{
			cin >> a;
			push_front(a);
		}
		else if (str == "push_back")
		{
			cin >> a;
			push_back(a);
		}
		else if (str == "pop_front")
			cout << pop_front() << endl;
		else if (str == "pop_back")
			cout << pop_back() << endl;
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