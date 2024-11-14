#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    // 차량의 진출 지점을 기준으로 오름차순 정렬
    sort(routes.begin(), routes.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });
    
    int answer = 0;
    int camera = -30001; // 카메라의 초기 위치를 가능한 최소값보다 작게 설정
    
    for (const auto& route : routes) {
        // 차량의 진입 지점이 현재 카메라 위치보다 크면 카메라를 설치해야 함
        if (route[0] > camera) {
            camera = route[1]; // 해당 차량의 진출 지점에 카메라 설치
            answer++;
        }
    }
    
    return answer;
}