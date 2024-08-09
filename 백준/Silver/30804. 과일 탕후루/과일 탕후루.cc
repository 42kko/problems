#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//완전탐색
// int countArr(int start, int end, vector<int> v, int *arr)
// {
//     int count;
//     while (start <= end)
//     {
//         arr[v[start] - 1]++;
//         arr[v[end] - 1]++;
//         count = 0;
//         for (int i = 0; i < 9; i++)
//             if (arr[i] != 0) count++;
//         if (count >= 3)
//         {
//             int arr1[9] = { 0,};
//             int arr2[9] = { 0,};
//             vector<int> v1 = v;
//             vector<int> v2 = v;
//             v1.erase(v1.begin(), v1.begin() + start);
//             v2.erase(v2.end() - (v2.size() - end), v2.end());
//             return max(countArr(0, v2.size(), v2, arr2),countArr(0, v1.size(), v1, arr1));
//         }
//         start++;
//         end--;
//     }
//     return v.size();
// }

// int main()
// {
//     vector<int> v;
//     int n, tmp;
//     cin >> n;
//     for(int i = 0; i < n; i++)
//     {
//         cin >> tmp;
//         v.push_back(tmp);
//     }
//     int start = 0;
//     int end = n - 1;
//     int arr[9] = { 0, };
//     cout << countArr(start, end, v, arr);
// }


int main()
{
    vector<int> v;
    int n, tmp, count = 0, ret = 0, start = 0;
    int arr[10] = { 0, };
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
        if (arr[tmp] == 0)
            count++;
        arr[tmp]++;
        while (count >= 3)
        {
            arr[v[start]]--;
            if (arr[v[start]] == 0)
                count--;
            start++;
        }
        ret = max(ret, int(v.size() - start));
    }
    cout << ret;
}