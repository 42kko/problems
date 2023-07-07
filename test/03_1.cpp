#include <iostream>
#include <string>
using namespace std;

int func2(int arr[], int n)
{
	int current[100];
	for (int i = 0; i < n; i++)
	{
		if (current[100 - arr[i]])
			return 1;
		current[arr[i]] = 1;
	}
	return 0;
}

int main()
{
	int arr[] = {1, 52, 48};
	int n = 3;
	cout << func2(arr, n) << endl;
}