#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 주사위의 맞은편 면을 찾기 위한 매핑
int getOpposite(int index) {
    switch (index) {
        case 0: return 5;
        case 1: return 3;
        case 2: return 4;
        case 3: return 1;
        case 4: return 2;
        case 5: return 0;
    }
    return -1; // 이 값은 실행되지 않음
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> dices(n, vector<int>(6));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> dices[i][j];
        }
    }
    
    int maxSum = 0;
    
    // 첫 번째 주사위의 모든 바닥 면 경우를 탐색
    for (int bottom = 0; bottom < 6; bottom++) {
        int currentSum = 0;
        int topValue = dices[0][getOpposite(bottom)]; // 첫 주사위의 천장 값
        
        // 각 주사위를 순차적으로 처리
        for (int i = 0; i < n; i++) {
            int bottomValue = topValue; // 이전 주사위의 천장이 현재 주사위의 바닥
            topValue = dices[i][getOpposite(find(dices[i].begin(), dices[i].end(), bottomValue) - dices[i].begin())];
            
            // 바닥과 천장을 제외한 옆면의 최댓값 계산
            int maxSideValue = 0;
            for (int j = 0; j < 6; j++) {
                if (dices[i][j] != bottomValue && dices[i][j] != topValue) {
                    maxSideValue = max(maxSideValue, dices[i][j]);
                }
            }
            currentSum += maxSideValue;
        }
        
        maxSum = max(maxSum, currentSum);
    }
    
    cout << maxSum << endl;
    return 0;
}