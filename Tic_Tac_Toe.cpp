/* TASK 3 : TIC-TAC-TOE GAME

Game Board: Create a 3x3 grid as the game board.
Players: Assign
"X"
and "O" to two players.

Display Board: Show the current state of the board.
Player Input: Prompt the current player to enter their move.
Update Board: Update the game board with the player
'
s move.

Check for Win: Check if the current player has won.
Check for Draw: Determine if the game is a draw.
Switch Players: Alternate turns between
"X"
and "O"

players.

Display Result: Show the result of the game (win, draw, or ongoing).
Play Again: Ask if the players want to play another game.*/

#include <iostream>
using namespace std;

// Function prototypes
void initializeBoard(char board[3][3]);
void displayBoard(char board[3][3]);
bool checkWin(char board[3][3], char player);
bool checkDraw(char board[3][3]);
bool isValidMove(char board[3][3], int row, int col);
void updateBoard(char board[3][3], int row, int col, char player);

int main() 
{
    char board[3][3];
    char currentPlayer = 'X';
    bool gameover = false;
    int row, col;
    char playAgain;

    do {
        // Initialize the board
        initializeBoard(board);

        // Game loop
        do {
            // Display the board
            displayBoard(board);

            // Get player move
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            // Check if the move is valid
            while (!isValidMove(board, row, col)) {
                cout << "Invalid move! Please enter your move (row and column): ";
                cin >> row >> col;
            }

            // Update the board with the player's move
            updateBoard(board, row, col, currentPlayer);

            // Check if the current player wins
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins! Congratulations!\n";
                gameover = true;
            }
            // Check if it's a draw
            else if (checkDraw(board)) {
                displayBoard(board);
                cout << "It's a draw!\n";
                gameover = true;
            }
            else {
                // Switch players
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } while (!gameover);

        // Ask to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        if (playAgain != 'y' && playAgain != 'Y') {
            cout << "Thanks for playing Tic-Tac-Toe!\n";
        }
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}

// Function definitions

void initializeBoard(char board[3][3]) 
{
    // Initialize the board with empty spaces
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(char board[3][3]) 
{
    // Display the current state of the board
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "-----------\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "-----------\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
}

bool checkWin(char board[3][3], char player) 
{
    // Check if the current player has won
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || // Check rows
            (board[0][i] == player && board[1][i] == player && board[2][i] == player) || // Check columns
            (board[0][0] == player && board[1][1] == player && board[2][2] == player) || // Check diagonal
            (board[0][2] == player && board[1][1] == player && board[2][0] == player))   // Check anti-diagonal
        {
            return true;
        }
    }
    return false;
}

bool checkDraw(char board[3][3]) 
{
    // Check if the game is a draw
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false; // There's still an empty space
            }
        }
    }
    return true; // All spaces are filled
}

bool isValidMove(char board[3][3], int row, int col) 
{
    // Check if the move is within the board and the cell is empty
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

void updateBoard(char board[3][3], int row, int col, char player) 
{
    // Update the board with the player's move
    board[row][col] = player;
}

