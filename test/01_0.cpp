#include <iostream>

void insert(int idx, int num, int arr[], int &len)
{
    for (int i = len; i > idx; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[idx] = num;
    len++;
}

void erase(int idx, int arr[], int& len)
{
    for (int i = idx; i < len; i++)
    {
        arr[i] = arr[i + 1];
    }
}

int main()
{
    int arr[10] = {10, 50, 40, 30, 70, 20};
    int len = 6;
    insert(3, 60, arr, len);
    for (int i = 0; arr[i]; i++)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;  
    erase(4, arr, len);
    for (int i = 0; arr[i]; i++)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;  
}