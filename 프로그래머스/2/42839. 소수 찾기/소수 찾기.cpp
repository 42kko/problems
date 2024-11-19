#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int ans;

/*
소수 판단
1과 자기자신으로만 나눠진다.
1. 2부터 (n/2)까지 넣는다.

*/

vector<bool> arr;
map<int, int> mp;

bool vist[1000000];

void primenum() {
    arr.resize(10000000, true);

    arr[0] = false;
    arr[1] = false;
    for (int i = 2; i < 10000000; ++i)
    {
        if (arr[i])
        {
            for (int j = i * 2; j < 10000000; j += i)
            {
                arr[j] = false;
            }
        }
    }
}

void recursion(string num, string nub) {
    if (arr[stoi(nub)]) {
        ans++;
        arr[stoi(nub)] = false;
    }
    for (int i = 0; i < num.size(); i++) {
        if (vist[i]) continue;
        vist[i] = true;
        mp[stoi(nub + num[i])] =  1;
        recursion(num, nub + num[i]);
        vist[i] = false;
    }
}

int solution(string numbers) {
    int answer = 0;
    primenum();
    recursion(numbers, "0");
    return ans;
}
