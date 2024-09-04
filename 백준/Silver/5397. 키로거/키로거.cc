#include <iostream>
#include <list>
#include <string>
using namespace std;

// 키로거를 설치
// 

int n;
list<char> lt;
list<char>::iterator iter;

int main () {
    cin >> n;
    string tmp;
    for (long long i = 0; i < n; i++) {
        lt.clear();
        iter = lt.begin();
        cin >> tmp;
        for (const char c : tmp) {
            if (isalnum(c)) {
                iter = lt.insert(iter, c);
                if (iter != lt.end()) iter++;
            }
            else if (c == '<' && iter != lt.begin()) {
                iter --;
            }
            else if (c == '>' && iter != lt.end()) {
                iter ++;
            }
            else if (c == '-') {
                if (!lt.empty()) {
                    if (iter == lt.begin()) {
                        continue;
                    }
                    iter--;
                    iter = lt.erase(iter);
                }
            }
        }
        for (const char c : lt) {
            cout << c;
        }
        cout << "\n";
    }
}