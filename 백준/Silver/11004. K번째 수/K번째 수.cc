#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    priority_queue<int> maxHeap;

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        if (maxHeap.size() < K) {
            maxHeap.push(num);
        } else {
            if (num < maxHeap.top()) {
                maxHeap.pop();
                maxHeap.push(num);
            }
        }
    }

    cout << maxHeap.top() << '\n';

    return 0;
}