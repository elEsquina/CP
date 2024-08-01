#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

bool isSafe(vector<int>& grid, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (grid[i] == col || abs(row - i) == abs(col - grid[i]))
            return false;
    }
    return true;
}

int getMoves(const vector<int>& originalGrid, const vector<int>& solvedGrid) {
    int moves = 0;
    for (int i = 0; i < 8; i++) {
        if (originalGrid[i] != solvedGrid[i])
            moves++;
    }
    return moves;
}

void solve(vector<int>& grid, const vector<int>& unsolved, int row, int& minMoves) {
    if (row == 8) {
        minMoves = min(minMoves, getMoves(unsolved, grid));
        return;
    }
    for (int col = 0; col < 8; col++) {
        if (isSafe(grid, row, col)) {
            grid[row] = col;
            solve(grid, unsolved, row + 1, minMoves);
        }
    }
}

int main() {
    vector<int> grid(8);
    int caseNumber = 0;

    while (cin >> grid[0]) {
        for (int j = 1; j < 8; j++)
            cin >> grid[j];
        for (int j = 0; j < 8; j++)
            grid[j]--;

        int minMoves = numeric_limits<int>::max();
        vector<int> initialGrid = grid; 
        solve(grid, initialGrid, 0, minMoves);

        cout << "Case " << ++caseNumber << ": " << minMoves << endl;
    }
    
    return EXIT_SUCCESS;
}
