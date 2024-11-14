#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;

    sort(routes.begin(), routes.end(), [](vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    });

    int mark = -30001;
    for (const auto e : routes) {
        if (e[0] > mark) {
            mark = e[1];
            answer++;
        }
    }
    return answer;
}