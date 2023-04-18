#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void draw_board(char board[][3]) {
    cout << "  1 2 3" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool is_winner(char board[][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

void computer_move(char board[][3]) {
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' ');

    board[row][col] = 'O';
    cout << "Computer chooses row " << row + 1 << " and column " << col + 1 << endl;
    draw_board(board);
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

    cout << "Welcome to Tic-Tac-Toe!" << endl;
    draw_board(board);

    srand(time(NULL));
    for (int i = 0; i < 9; i++) {
        int row, col;
        cout << "Player X, enter row and column (e.g., 2 3): ";
        cin >> row >> col;

        while (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Invalid move. Please try again." << endl;
            cout << "Player X, enter row and column (e.g., 2 3): ";
            cin >> row >> col;
        }

        board[row - 1][col - 1] = 'X';
        draw_board(board);

        if (is_winner(board, 'X')) {
            cout << "Player X wins!" << endl;
            return 0;
        }

        if (i == 8) {
            cout << "It's a tie!" << endl;
            return 0;
        }

        computer_move(board);

        if (is_winner(board, 'O')) {
            cout << "Computer wins!" << endl;
            return 0;
        }
    }

    return 0;
}
