#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int kadane(const vector<int>& arr, int* start, int* finish) {
    int sum = 0, maxSum = INT_MIN;
    int n = arr.size();

    *finish = -1;
    int local_start = 0;

    for (int i = 0; i < n; ++i) {
        sum += arr[i];
        if (sum < 0) {
            sum = 0;
            local_start = i + 1;
        } else if (sum > maxSum) {
            maxSum = sum;
            *start = local_start;
            *finish = i;
        }
    }

    if (*finish != -1)
        return maxSum;

    maxSum = arr[0];
    *start = *finish = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] > maxSum) {
            maxSum = arr[i];
            *start = *finish = i;
        }
    }

    return maxSum;
}

void findMaxSum(const vector<vector<int>>& M) {
    int maxSum = INT_MIN, finalLeft, finalRight, finalTop, finalBottom;

    int ROW = M.size();
    int COL = M[0].size();

    for (int left = 0; left < COL; ++left) {
        vector<int> temp(ROW, 0);

        for (int right = left; right < COL; ++right) {
            for (int i = 0; i < ROW; ++i)
                temp[i] += M[i][right];

            int start, finish;
            int sum = kadane(temp, &start, &finish);

            if (sum > maxSum) {
                maxSum = sum;
                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = finish;
            }
        }
    }
}

int main() {
    int n;

    cin >> n;
    vector<vector<int>> M(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> M[i][j];
        }
    }

    findMaxSum(M);

    return EXIT_SUCCESS;
}
