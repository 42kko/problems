#include<bits/stdc++.h>
using namespace std;

char dat[600005];
int pre[600005], nxt[600005];
int unused = 1;
int len = 0;

bool isLower(string s)
{
	for (char c :  s)
	{
		if (!islower(c))
			return false;
	}
	return true;
}

void insert(int arr, char s)
{
	dat[unused] = s;
	pre[unused] = arr;
	nxt[unused] = nxt[arr];
	if (nxt[arr] != -1)
		pre[nxt[arr]] = unused;
	nxt[arr] = unused;
	unused++;
	len++;
}

void erase(int arr)
{
	nxt[pre[arr]] = nxt[arr];
	pre[nxt[arr]] = pre[arr];
	len--;
}


void fillList(string s)
{
	for (int i = 0; i < s.size(); i++)
		insert(i, s[i]);
}

void traverse()
{
	int cur = nxt[0];
	while (cur != -1)
	{
		cout << dat[cur];
		cur = nxt[cur];
	}
	cout << "\n";
}

int main()
{
	fill(pre, pre+10005, -1);
	fill(nxt, nxt+10005, -1);
	string s;
	int cnt;
	cin >> s >> cnt;
	if (s.size() > 100000 || cnt > 500000 || cnt < 1 || !isLower(s))
		return 1;
	fillList(s);
	int cursor = s.size();
	for (int i = 0; i < cnt; i++)
	{
		char c;
		cin >> c;
		if (c == 'P')
		{
			char c1;
			cin >> c1;
			insert(cursor, c1);
			cursor = nxt[cursor];
		}
		else if (c == 'L')
		{
			cursor = pre[cursor] != -1 ? pre[cursor] : 0;
		}
		else if (c == 'D')
		{
			cursor = nxt[cursor] != -1 ? nxt[cursor] : cursor;
		}
		else if (c == 'B' && cursor != 0)
		{
			erase(cursor);
			cursor = pre[cursor];
		}
	}
	traverse();
}