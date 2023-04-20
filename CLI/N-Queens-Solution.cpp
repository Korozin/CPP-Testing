#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<int>& board, int row, int col, int n) {
    // Check if this row on left side
    for (int i = 0; i < col; i++) {
        if (board[i] == row || board[i] == row - (col - i) || board[i] == row + (col - i)) {
            return false;
        }
    }
    return true;
}

void solveNQueens(vector<int>& board, int col, int n, vector<vector<int>>& results) {
    if (col == n) {
        results.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++) {
        if (isSafe(board, row, col, n)) {
            board[col] = row;
            solveNQueens(board, col + 1, n, results);
            board[col] = -1;
        }
    }
}

vector<vector<int>> nQueens(int n) {
    vector<vector<int>> results;
    vector<int> board(n, -1);
    solveNQueens(board, 0, n, results);
    return results;
}

int main() {
    int n = 4;
    vector<vector<int>> results = nQueens(n);
    for (int i = 0; i < results.size(); i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (results[i][j] == k) {
                    cout << "Q ";
                } else {
                    cout << ". ";
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
