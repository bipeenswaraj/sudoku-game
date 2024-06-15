// #include<iostream>
// using namespace std;
// int main(){
//     cout<<"solve this sudoku";
    
//     int game[9][9]={
//         {5, 3, 0, 0, 7, 0, 0, 0, 0},
//         {6, 0, 0, 1, 9, 5, 0, 0, 0},
//         {0, 9, 8, 0, 0, 0, 0, 6, 0},
//         {8, 0, 0, 0, 6, 0, 0, 0, 3},
//         {4, 0, 0, 8, 0, 3, 0, 0, 1},
//         {7, 0, 0, 0, 2, 0, 0, 0, 6},
//         {0, 6, 0, 0, 0, 0, 2, 8, 0},
//         {0, 0, 0, 4, 1, 9, 0, 0, 5},
//         {0, 0, 0, 0, 8, 0, 0, 7, 9}};
//     for(int i = 0;i<9;i++){
//         for(int j=0;j<9;j++){
//             cout<<game[i][j]<<" ";
//         }
//         cout<<endl;
//     }
    
//     return 0;    
// }
#include <iostream>

// Function to print the Sudoku board
void printBoard(int board[9][9]) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            std::cout << board[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

// Function to check if placing num in the specified cell is valid
bool isValid(int board[9][9], int row, int col, int num) {
    // Check the row
    for (int x = 0; x < 9; ++x) {
        if (board[row][x] == num) {
            return false;
        }
    }

    // Check the column
    for (int x = 0; x < 9; ++x) {
        if (board[x][col] == num) {
            return false;
        }
    }

    // Check the 3x3 sub-grid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Function to solve the Sudoku board 
bool solveSudoku(int board[9][9]) {
    int row = -1;
    int col = -1;
    bool isEmpty = false;

    // Find an empty cell
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) {
            break;
        }
    }

    //no empty
    if (!isEmpty) {
        return true;
    }

    //giving input
    for (int num = 1; num <= 9; ++num) {
        if (isValid(board, row, col, num)) {
            board[row][col] = num;

            // Recur to solve the rest of the board
            if (solveSudoku(board)) {
                return true;
            }

            // Undo the current cell for backtracking
            board[row][col] = 0;
        }
    }

    return false; // Trigger backtracking
}

int main() {
    int board[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudoku(board)) 
    {
        printBoard(board);
    } 
    else
    {
        std::cout << "No solution exists" << std::endl;
    }

    return 0;
}
