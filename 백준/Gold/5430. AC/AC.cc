#include<iostream>
#include<string>
#include<deque>
#include<algorithm>
using namespace std;
#define REVERSE 1
#define FORWARD 0
// R(뒤집기) D(버리기)
// R 순서 리버스, D 첫번째 수 버리기 + 배열없는데 D할시 에러
//

bool state;
int t, n, front, back;
string p;
string tmp;
deque<int> d;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    int flag;
    for (int i = 0; i < t; i++)
    {
        flag = 0;
        state = FORWARD;
        cin >> p >> n >> tmp;
        for (int j = 0; j < tmp.size(); j++)
        {
            if (isdigit(tmp[j]))
            {
                if (j + 2 < tmp.size() && isdigit(tmp[j + 1]) && isdigit(tmp[j + 2]))
                {
                    d.push_back(stoi(tmp.substr(j, 3)));
                    j += 2;
                }
                else if (j + 1 < tmp.size() && isdigit(tmp[j + 1]))
                {
                    d.push_back(stoi(tmp.substr(j, 2)));
                    j++;
                }
                else
                    d.push_back(tmp[j] - '0');
            } 
        }
        for (int j = 0; j < p.size(); j++)
        {
            if (p[j] == 'R')
            {
                if (state) state = FORWARD;
                else state = REVERSE;
            }
            else if (p[j] == 'D')
            {
                if (d.size() == 0)
                {
                    flag = 1;
                    break;
                }
                else
                {
                    if (state == REVERSE) d.pop_back();
                    else if (state == FORWARD) d.pop_front();
                }
            }
        }
        if (!d.size() && flag)  cout << "error";
        else if (state == FORWARD)
        {
            // cout << '[';
            // for (const int e : d)
            // {
            //     cout << d.front();
            //     if (d.size() != 1) cout << ',';
            //     d.pop_front();
            // }
            // cout << ']';
            cout << '[';
            while(!d.empty())
            {
                cout << d.front();
                d.pop_front();
                if(!d.empty()) cout << ',';
            }
            cout << ']';
        }
        else if (state == REVERSE)
        {
            // cout << '[';
            // for (const int e : d)
            // {
            //     cout << d.back();
            //     if (d.size() != 1) cout << ',';
            //     d.pop_back();
            // }
            // cout << ']';
                        cout << '[';
            while(!d.empty())
            {
                cout << d.back();
                d.pop_back();
                if(!d.empty()) cout << ',';
            }
            cout << ']';
        }
        cout << '\n';
    }
}