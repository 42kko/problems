#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
문제해석
N개의 정수로 이루어진 수열 두수의 차이가 M이상이면서 제일 작은 경우
1,4 1,5 2,5  1,5차이는 M이상지만 크다.
갯수 차이
한줄씩 배열의 숫자
정렬이후에 찾을껀지, 정렬안한상태에서 하나 찾을껀지->O(엔의 엔제곱)
백억번 초당 1~5억,
*/
int n, m, tmp, s = 0, e = 0;
vector<int> v;
int ret = 2147483647;

int main ()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        if (ret == m)
            break;
        while(e < v.size())
        {
            if (v[e] - v[s] >= m)
            {
                ret > v[e] - v[s] ? ret = v[e] - v[s] : 0;
                break;
            }
            e++;
        }
        s++;
    }
    cout << ret;
}