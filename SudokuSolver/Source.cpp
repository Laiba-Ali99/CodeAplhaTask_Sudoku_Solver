#include <iostream>
#include <vector>

using namespace std;


const int N = 9;

void printGrid(const vector<vector<int>>& grid) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

bool canPlaceNumber(vector<vector<int>>& grid, int row, int col, int num) {

    for (int i = 0; i < N; ++i) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }

    int boxStartRow = row - row % 3;
    int boxStartCol = col - col % 3;
    for (int i = boxStartRow; i < boxStartRow + 3; ++i) {
        for (int j = boxStartCol; j < boxStartCol + 3; ++j) {
            if (grid[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(vector<vector<int>>& grid) {
    int row, col;

    bool isEmpty = false;
    for (row = 0; row < N; ++row) {
        for (col = 0; col < N; ++col) {
            if (grid[row][col] == 0) {
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) {
            break;
        }
    }

    if (!isEmpty) {
        return true;
    }

    for (int num = 1; num <= 9; ++num) {

        if (canPlaceNumber(grid, row, col, num)) {

            grid[row][col] = num;


            if (solveSudoku(grid)) {
                return true;
            }

            grid[row][col] = 0;
        }
    }

    return false;
}

int main() {
    vector<vector<int>> grid = {
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

    cout << "Sudoku puzzle to solve:" << endl;
    printGrid(grid);

    if (solveSudoku(grid)) {
        cout << "\nSolution:" << endl;
        printGrid(grid);
    } else {
        cout << "\nNo solution exists." << endl;
    }

    return 0;
}
