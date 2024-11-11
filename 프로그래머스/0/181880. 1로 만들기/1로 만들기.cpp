#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int solution(vector<int> num_list) {
    int ans = 0;
    for (const int e : num_list) {
        int i = 0;
        while (1) {
            if (e < pow(2, i))
                break;
            i++;
        }
        ans += i - 1;
    }
    return ans;
}