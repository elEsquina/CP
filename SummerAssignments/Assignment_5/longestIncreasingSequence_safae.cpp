#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int LIS(vector<vector<int>> M, int n, int m) {
    vector<int> lis(n * m, 1);
    int row, col, prow, pcol;

    for (int i = 1; i < n * m; i++) {
        row = i / m;
        col = i % m;

        for (int prev = 0; prev < i; prev++) {
            prow = prev / m;
            pcol = prev % m;

            if ((pcol == col || prow == row) && M[row][col] > M[prow][pcol]) {
                lis[i] = max(lis[prev] + 1, lis[i]);
            }
        }
    }

    return *max_element(lis.begin(), lis.end());
}

int main() {
    int n, m;

    while(true) {
        cin >> n >> m;
        if (n == 0)
            break;

        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> matrix[i][j];
            }
        }

        cout << LIS(matrix, n, m) << endl;
    }
    return EXIT_SUCCESS;
}