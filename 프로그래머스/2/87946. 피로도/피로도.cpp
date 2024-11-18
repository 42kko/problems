#include <string>
#include <vector>
using namespace std;

/*
시작 - 최소 필요 피로도
끝 - 소모 피로도

완전 탐색해야할듯
*/

int answer = -1;
bool vist[10];

void recursion(int hp, vector<vector<int> > &arr, int cnt) {
    answer = max(answer, cnt);

    for (int i = 0; i < arr.size(); i++) {
        if (vist[i] || (hp - arr[i][0]) < 0) continue;
        vist[i] = true;
        recursion(hp - arr[i][1], arr, cnt + 1);
        vist[i] = false;
    }
}


int solution(int hp, vector<vector<int>> dungeons) {
    recursion(hp, dungeons, 0);
    return answer;
}