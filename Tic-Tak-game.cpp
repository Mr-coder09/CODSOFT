#include <iostream>
#include <vector>

using namespace std;


void displayBoard(const vector<vector<char>>& board) {
    cout << "   0 1 2" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i << "  ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}


bool checkWin(const vector<vector<char>>& board, char player) {
    
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    return false;
}


bool checkDraw(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ')
                return false;
        }
    }
    return true;
}

int main() {
    char currentPlayer = 'X';
    char playAgain;

    do {
        vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize the board
        bool gameWon = false;

        cout << "Welcome to Tic-Tac-Toe!\n";

       
        while (!gameWon && !checkDraw(board)) {
            
            cout << "Current board:\n";
            displayBoard(board);

           
            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            
            if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
                cout << "Invalid move. Try again.\n";
                continue;
            }

           
            board[row][col] = currentPlayer;

            
            if (checkWin(board, currentPlayer)) {
                gameWon = true;
                cout << "Player " << currentPlayer << " wins!\n";
            } else {
                
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }

       
        cout << "Final board:\n";
        displayBoard(board);

       
        if (!gameWon && checkDraw(board)) {
            cout << "It's a draw!\n";
        }

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing!\n";

    return 0;
}
