#include <string>
#include <vector>

using namespace std;

/*
a, aa, aaa, ... uuuuu
완전탐색을해야하나?
*/

string arr = "AEIOU";
int cnt = 0;
int answer = 0;

void recursion(string word, string tmp) {
    if (tmp.size() > 5)
        return;
    cnt++;
    if (word == tmp) {
        answer = cnt;
        return;
    }

    for (int i = 0; i < arr.size(); i++) {
        tmp.push_back(arr[i]);
        recursion(word, tmp);
        tmp.pop_back();
    }
}

int solution(string word) {
    recursion(word, "");
    return answer - 1;
}

