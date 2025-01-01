#include <iostream>
#include <limits> // INT_MAX 사용
using namespace std;

int main() {
    int sum = 0; // 홀수의 합
    int minOdd = 1e9; // 최소 홀수값 초기화
    bool hasOdd = false; // 홀수 존재 여부

    for (int i = 0; i < 7; i++) {
        int num;
        cin >> num; // 정수 입력
        if (num % 2 == 1) { // 홀수인지 확인
            sum += num; // 홀수 합계에 추가
            minOdd = min(minOdd, num); // 최소 홀수값 갱신
            hasOdd = true; // 홀수 존재 여부 갱신
        }
    }

    if (hasOdd) {
        cout << sum << '\n' << minOdd << '\n'; // 홀수의 합과 최소값 출력
    } else {
        cout << -1 << '\n'; // 홀수가 없을 경우
    }

    return 0;
}
