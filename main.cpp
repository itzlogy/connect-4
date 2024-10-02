#include <thread>
#include<chrono>
#include <iostream>
#include<windows.h>
using namespace std;
const int ROWS = 7;
const int COLS = 7;
const char EMPTY = ' ';
const char PLAYER1 = 'X';
const char PLAYER2 = 'O';
void createBoard(char board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            board[i][j] = EMPTY;
        }
    }
}

void printBoard(const char board[ROWS][COLS]) {
    system("cls");
    cout << endl << "-1-+-2-+-3-+-4-+-5-+-6-+-7-+" << endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << " " << board[i][j] << " |";
        }
        cout << endl << "---+---+---+---+---+---+---+" << endl;
    }
}

bool makeMove(char board[ROWS][COLS], int col, char player) {
    if (col < 0 || col >= COLS || board[0][col] != EMPTY) {
        return false;
    }
    for (int i = ROWS - 1; i >= 0; --i) {
        if (board[i][col] == EMPTY) {
            board[i][col] = player;
            return true;
        }
    }
    return false;
}

bool checkWin(const char board[ROWS][COLS], char player) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS - 3; ++j) {
            if (board[i][j] == player && board[i][j + 1] == player &&
                board[i][j + 2] == player && board[i][j + 3] == player) {
                return true;
            }
        }
    }

    for (int i = 0; i < ROWS - 3; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (board[i][j] == player && board[i + 1][j] == player &&
                board[i + 2][j] == player && board[i + 3][j] == player) {
                return true;
            }
        }
    }

    for (int i = 0; i < ROWS - 3; ++i) {
        for (int j = 0; j < COLS - 3; ++j) {
            if (board[i][j] == player && board[i + 1][j + 1] == player &&
                board[i + 2][j + 2] == player && board[i + 3][j + 3] == player) {
                return true;
            }
        }
    }

    for (int i = 0; i < ROWS - 3; ++i) {
        for (int j = 3; j < COLS; ++j) {
            if (board[i][j] == player && board[i + 1][j - 1] == player &&
                board[i + 2][j - 2] == player && board[i + 3][j - 3] == player) {
                return true;
            }
        }
    }
    return false;

}
int main() {
    char board[ROWS][COLS];
    createBoard(board);

    char currentPlayer = PLAYER1;
    bool gameWon = false;
    int moveCount = 0;
printBoard(board);
    while (true) {
        cout << "Player " << currentPlayer << ", enter a column number (1-7) to make a move: ";
         int col;
        cin >> col;
         if (cin.fail())
{
     cin.clear(); cin.ignore(512, '\n');
}
        if (makeMove(board, col - 1, currentPlayer)) {
            gameWon = checkWin(board, currentPlayer);
            currentPlayer = (currentPlayer == PLAYER1) ? PLAYER2 : PLAYER1;
            moveCount++;
        }
        else {
            cout << "Invalid move. Try again." << endl;
        Sleep(1000);
        }
    printBoard(board);
    if (gameWon) {
        cout << "Player " << (currentPlayer == PLAYER1 ? PLAYER2 : PLAYER1) << " wins!" << endl;
        break;
    }
    else if (moveCount==49) {
        cout << "The game is a draw." << endl;
        break;
    }
    }
     char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;
    if (playAgain == 'y') {
        main();
    }

    return 0;
}