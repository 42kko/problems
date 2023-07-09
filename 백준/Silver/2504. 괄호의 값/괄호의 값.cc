#include <bits/stdc++.h>
using namespace std;
int ans = 0;

void cal(stack<string> &s, char c)
{
    char a = c == ']' ? '[' : '(';
    string conv(1, a);
    while (!s.empty())
    {
        string tmp = s.top();
        s.pop();
        if (s.empty())
            break;
        if ((s.top() == "(" && conv == "[") ||(s.top() == "[" && conv == "("))
        {
            s.push(tmp);
            break;
        }
        else if (s.top() == conv)
        {
            s.pop();
            int x = c == ']' ? 3 : 2;
            s.push(to_string(stoi(tmp) * x));
            break;
        }
        else
        {
            string str = s.top();
            s.pop();
            s.push(to_string(stoi(str) + stoi(tmp)));
        }
        if (s.size() == 1)
            break;
    }
    return;
}

bool valid(string &str)
{
    stack<char> s;
    for (auto c: str)
    {
        if (c == '(')
            s.push(c);
        else if (c == ')')
        {
            if (s.empty())
                return false;
            else if (s.top() == '[')
                return false;
            s.pop();
        }
        else if (c == '[')
            s.push(c);
        else if (c == ']')
        {
            if (s.empty())
                return false;
            else if (s.top() == '(')
                return false;
            s.pop();
        }
    }
    if (!s.empty())
        return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin >> str;
    stack<string> s;
    if (!valid(str))
    {
        cout << "0" << endl;
        return 0;
    }
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(' && str[i + 1] == ')')
        {
            s.push("2");
            i++;
        }
        else if (str[i] == '(')
            s.push("(");
        else if (str[i] == '[' && str[i + 1] == ']')
        {
            s.push("3");
            i++;
        }
        else if (str[i] == '[')
            s.push("[");
        else if (str[i] == ')' || str[i] == ']')
        {
            cal(s, str[i]);
        }
    }
    int i = 0;
    while (!s.empty())
    {
        i += stoi(s.top());
        s.pop();
    }
    cout << to_string(i) << endl;
    return 0;
}
