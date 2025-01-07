#include <iostream>
using namespace std;

int n;
int arr[25];
int board[25];
int cols[50];
int right_diag[50];
int left_diag[50];

void recursion(int row) {
    if (row == n) {
        for (int i = 0; i < n; i++) 
            cout << board[i] + 1 << '\n';
        exit(0);
    }
    if (arr[row] != -1) {
        recursion(row + 1);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (cols[col] || left_diag[row - col + n] || right_diag[row + col]) continue;
        cols[col] =  left_diag[row - col + n] = right_diag[row + col] = true;
        board[row] = col;
        recursion(row + 1);
        cols[col] =  left_diag[row - col + n] = right_diag[row + col] = false;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]--;
        if (arr[i] != -1) {
            cols[arr[i]] = left_diag[i - arr[i] + n] = right_diag[i + arr[i]] = true;
            board[i] = arr[i];
        }
    }
    recursion(0);
    cout << -1;
}