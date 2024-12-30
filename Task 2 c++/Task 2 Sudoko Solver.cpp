#include <iostream>
#include <vector>
//sudoko game
#define N 9

using namespace std;

// Print the Sudoku board
void printBoard(const vector<vector<int> >& board)
{
    for (int r = 0; r < N; r++) {
        for (int d = 0; d < N; d++) {
            cout << board[r][d] << " ";
        }
        cout << endl;
    }
}

// Function to check if placing a number in the cell is safe
bool isSafe(const vector<vector<int> >& board, int row,
            int col, int num)
{
    for (int x = 0; x < N; x++) {
        if (board[row][x] == num) {
            return false;
        }
    }

    for (int x = 0; x < N; x++) {
        if (board[x][col] == num) {
            return false;
        }
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

// Function to solve the Sudoku using Backtracking approach
bool solveSudokuBacktracking(vector<vector<int> >& board)
{
    int row = -1;
    int col = -1;
    bool isEmpty = true;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty) {
            break;
        }
    }

    if (isEmpty) {
        return true;
    }

    for (int num = 1; num <= 9; num++) {
        if (isSafe(board, row, col, num)) {
            board[row][col] = num;

            if (solveSudokuBacktracking(board)) {
                return true;
            }

            board[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    // Declare a 9x9 board
    vector<vector<int> > board(N, vector<int>(N));

    // Prompt the user to enter the Sudoku grid
    cout << "Enter your Sudoku grid (9x9), use 0 for empty cells:" << endl;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            // Validate the input for each cell, it should be a number from 0 to 9
            if (board[i][j] < 0 || board[i][j] > 9) {
                cout << "Invalid input, please enter numbers between 0 and 9." << endl;
                return -1;
            }
        }
    }

    // Solve the Sudoku and print the result
    if (solveSudokuBacktracking(board)) {
        cout << "Solved Sudoku board:" << endl;
        printBoard(board);
    } else {
        cout << "No solution exists" << endl;
    }

    return 0;
}
