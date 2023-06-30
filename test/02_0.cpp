#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    // std::vector<int> v1 = {1, 2, 3, 4, 5, 6};
    int arr[] = {1, 2, 3, 4, 5, 6};
    std::vector<int> v1(arr, arr + sizeof(arr) / sizeof(arr[0]));

    for(int e : v1)
        std::cout << e << ' ';
    for (int i = 0; i < v1.size(); i++)
        std::cout << v1[i] << ' ';
}