#include <iostream>
using namespace std;

int board[10];
int n;

bool check(int row, int col) {
    for (int i = 1; i < row; i++) {
        if (board[i] == col) {
            return false;
        }

        if ((board[i] - i) == (col - row)) {
            return false;
        }

        if ((board[i] + i) == (col + row)) {
            return false;
        }
    }

    return true;
}

void printSolution() {
    cout << "\nSolution:\n";

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (board[i] == j) {
                cout << "Q ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
}

void nQueen(int row) {
    if (row > n) {
        printSolution();
        return;
    }

    for (int col = 1; col <= n; col++) {
        if (check(row, col)) {
            board[row] = col;
            nQueen(row + 1);
        }
    }
}

int main() {
    cout << "Enter number of queens: ";
    cin >> n;

    nQueen(1);

    return 0;
}