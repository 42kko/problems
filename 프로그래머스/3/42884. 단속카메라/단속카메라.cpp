#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    // 차량의 진출 지점을 기준으로 오름차순 정렬
    sort(routes.begin(), routes.end(), [](vector<int> a, vector<int> b) {
        return a[1] < b[1];
    });
    
    int answer = 0;
    int camera = -30001; // 카메라의 초기 위치를 가능한 최소값보다 작게 설정
    
    for (const auto& route : routes) {
        if (route[0] > camera) {
            camera = route[1];
            answer++;
        }
    }
    
    return answer;
}