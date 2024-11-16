#include <string>
#include <vector>
using namespace std;

/*
1번 - 12345 ...
2번 - 21 22 23 24 25 ...
3번 - 33 11 22 44 55 ...
*/

int a1[10] = {1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
int a2[10] = {2, 1, 2, 3, 2, 4, 2, 5};
int a3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 0; i < answers.size(); i++) {
        if (a1[i % 10] == answers[i])
            cnt1++;
        if (a2[i % 8] == answers[i])
            cnt2++;
        if (a3[i % 10] == answers[i])
            cnt3++;
    }
    if (cnt1 >= cnt2 && cnt1 >= cnt3)
        answer.push_back(1);
    if (cnt2 >= cnt1 && cnt2 >= cnt3)
        answer.push_back(2);
    if (cnt3 >= cnt1 && cnt3 >= cnt2)
        answer.push_back(3);
    return answer;
}