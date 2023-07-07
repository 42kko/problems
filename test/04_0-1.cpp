#include <bits/stdc++.h>
using namespace std;

int main()
{
  list<int> L = {1, 2};
  list<int>::iterator t = L.begin();
  L.push_front(10);
  cout << *t << endl;
  L.push_back(5);
  L.insert(t, 6);
  t++;
  t = L.erase(t);
  cout << *t << endl;
  for (auto i : L)
    cout << i << ' ';
  for (list<int>::iterator it = L.begin(); it != L.end(); it++)
    cout << *it << ' ';
}