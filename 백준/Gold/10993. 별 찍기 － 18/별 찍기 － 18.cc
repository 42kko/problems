#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

/*
밑변이 x2 + 3 씩 늘어남 1, 5, 13, 29
높이는 x2 + 1 씩 늘어남
*/

int n;
char arr[3000][3000];

int calcBase(int n) {
    if (n == 1)
        return 1;
    return (2 * calcBase(n - 1) + 3);
}

int calcHeight(int n) {
    if (n == 1)
        return 1;
    return (2 * calcHeight(n - 1) + 1);
}

void makeStar(pair<int, int> starting, int n) {
    if (n == 1) {
        arr[starting.first][starting.second] = '*';
        return;
    }
    int x = starting.first, y = starting.second;
    int height = calcHeight(n), base = calcBase(n);
    int nx, ny;

    if (n % 2 == 0) {
        for (int i = 0; i < height; i++) {
            arr[x + i][y + i] = '*';
            arr[x + i][y + base - 1 - i] = '*';
        }
        for (int j = 0; j < base; j++) {
            arr[x][y + j] = '*';
        }
        nx = x + 1;
        ny = y + (base - calcBase(n - 1)) / 2;
    } 
    else {
        for (int i = 0; i < height; i++) {
            arr[x + height - 1 - i][y + i] = '*'; 
            arr[x + height - 1 - i][y + base - 1 - i] = '*'; 
        }
        for (int j = 0; j < base; j++) {
            arr[x + height - 1][y + j] = '*';
        }
        nx = x + height / 2;
        ny = y + (base - calcBase(n - 1)) / 2;
    }

    makeStar({nx, ny}, n - 1);
}

int main() {
    cin >> n;

    for (int i = 0; i < calcHeight(n); i++) {
        for (int j = 0; j < calcBase(n); j++) {
            arr[i][j] = ' ';
        }
    }

    makeStar({0, 0}, n);
    for (int i = 0; i < calcHeight(n); i++) {
        int lastStar = calcBase(n) - 1;
        while (lastStar > 0 && arr[i][lastStar] == ' ') {
            lastStar--;
        }
        for (int j = 0; j <= lastStar; j++) {
            cout << arr[i][j];
        }
        cout << '\n';
    }
}
