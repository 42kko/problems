#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> answer;
vector<pair<int, int>> obj[50005];  // 인접 리스트
int dist[50005];  // 최소 intensity 저장
bool summit[50005];  // 산봉우리 체크 배열
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // 우선순위 큐

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    // 그래프 초기화
    for (int i = 0; i < paths.size(); i++) {
        auto cur = paths[i];
        obj[cur[0]].push_back({cur[2], cur[1]});
        obj[cur[1]].push_back({cur[2], cur[0]});
    }
    
    // 거리 배열 초기화
    fill(dist, dist + n + 1, 1e9);
    fill(summit, summit + n + 1, false);  // summit 배열 초기화

    // 산봉우리 체크
    for (const auto e : summits) {
        summit[e] = true;
    }

    // 출입구 설정
    for (const auto e : gates) {
        dist[e] = 0;
        pq.push({dist[e], e});
    }

    // 다익스트라 실행 (intensity 최소화)
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();

        // 이미 최적의 intensity보다 높은 경우 스킵
        if (dist[cur.second] < cur.first) continue;

        // 산봉우리에 도착하면 탐색 중단
        if (summit[cur.second]) continue;

        for (auto nxt : obj[cur.second]) {
            int new_intensity = max(dist[cur.second], nxt.first);  // 경로에서 가장 큰 가중치 유지
            if (new_intensity < dist[nxt.second]) {
                dist[nxt.second] = new_intensity;
                pq.push({dist[nxt.second], nxt.second});
            }
        }
    }

    // 최소 intensity를 가지는 산봉우리 찾기
    int ans_summit = -1, ans = 1e9;
    for (const auto e : summits) {
        if (dist[e] != 1e9 && dist[e] < ans) {  // 경로가 있는 경우만 고려
            ans = dist[e];
            ans_summit = e;
        } else if (dist[e] != 1e9 && dist[e] == ans && e < ans_summit) {  // 같은 intensity일 때 번호가 작은 산봉우리 선택
            ans_summit = e;
        }
    }

    // 도달 가능한 산봉우리가 없는 경우 예외 처리
    if (ans_summit == -1) return {-1, -1};

    // 결과 저장 (answer 초기화 후 삽입)
    answer.clear();
    answer.push_back(ans_summit);
    answer.push_back(ans);
    return answer;
}