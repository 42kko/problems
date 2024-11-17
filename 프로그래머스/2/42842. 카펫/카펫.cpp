#include <string>
#include <vector>
using namespace std;

/*
중앙에 위치해야하는 노랑
외곽에 위치해야하는 갈색

노랑과 갈색 수를 주어주면 가로 세로를 출력

- - - - - - 14,4   6, 3
- * * * * -
- - - - - -

- - - - 12,4  4, 4
- * * -
- * * -
- - - -

14 + 4 = 6 * 3
12 + 4 = 4 * 4

height 를 통해 width
height <= width
*/

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for (int height = 3; height * height <= (brown + yellow); height++) {
        if ((brown + yellow) % height != 0) continue;
        int width = (brown + yellow) / height;
        if ((height - 2) * (width - 2) == yellow) {
            answer.push_back(width);
            answer.push_back(height);
            break;
        }
    }
    return answer;
}