#include <string>
#include <vector>
#include <iostream>
using namespace std;

/*
시간을 체크해야함.
모든 심사관을 풀로돌렸을때 몇명이 처리가능한지를 체크하는방식
0, 1e9를 시간으로 잡고 해당시간에 몇명을 처리했는지
*/

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    long long left = 0, right = 1e18;
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long tmp = 0;
        for (int i = 0; i < times.size(); i++) {
            tmp += mid / times[i];
        }
        if (tmp >= n) {
            answer = mid;
            right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return answer;
}