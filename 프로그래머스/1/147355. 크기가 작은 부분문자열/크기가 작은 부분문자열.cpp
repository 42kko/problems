#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    size_t tLen = t.size();
    size_t pLen = p.size();
    for (int i = 0; i <= tLen - pLen; i++) {
        string tmp = t.substr(i, pLen);
        if (tmp <= p)
                answer++;
    }
    return answer;
}