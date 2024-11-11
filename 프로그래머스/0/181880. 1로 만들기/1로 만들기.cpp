#include <vector>
int solution(std::vector<int> num_list) {
    int ans = 0;
    for (const int e : num_list) {
        int i = 0;
        while (e >= (1 << i)) 
            ++i;
        ans += i - 1;
    }
    return ans;
}