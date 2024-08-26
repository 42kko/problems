#include<iostream>
#include<queue>
using namespace std;
//먼저온대로 처리 -> queue
//queue 크기 n

int n;

int main()
{
    queue<int> q;
    int tmp;
    cin >> n;
    while (1)
    {
        cin >> tmp;
        if (tmp == -1)
            break;
        else if (tmp == 0)
        {
            q.pop();
            continue;
        }
        else if (q.size() == n)
            continue;
        q.push(tmp);
    }
    if (q.empty())
        cout << "empty";
    else
    {
        for (int i = 0; i < q.size(); i++)
        {
            cout << q.front() << " ";
            q.pop();
            i--;
        }
    }
}