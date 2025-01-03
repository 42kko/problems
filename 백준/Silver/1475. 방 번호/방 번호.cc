#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int arr[10];  // 0부터 9까지의 숫자 세트

int main() {
    int a;
    cin >> a;

    string b = to_string(a);

    for (char c : b) {
        int num = c - '0';  // 문자를 숫자로 변환
        arr[num]++;
    }

    // 6과 9를 동일하게 취급
    int sixNineCount = (arr[6] + arr[9] + 1) / 2; // 올림 계산

    // 가장 많이 필요한 숫자 세트 개수 계산
    int maxSetCount = 0;
    for (int i = 0; i < 10; i++) {
        if (i == 6 || i == 9) continue; // 6과 9는 따로 처리
        maxSetCount = max(maxSetCount, arr[i]);
    }

    maxSetCount = max(maxSetCount, sixNineCount);

    cout << maxSetCount << endl;
    return 0;
}