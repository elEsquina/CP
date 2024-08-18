#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


int maxSubArray(vector<int> routes, int n) {
    int nicest = -1;  
    int nice = 0;
    int start = 1, end = 1, tempStart = 1;
    
    for (int i = 1; i <= n; i++) {  
        nice += routes[i];

        if (nice > nicest || (nice == nicest && (i - tempStart > end - start))) {
            nicest = nice;
            start = tempStart;  
            end = i;            
        }

        if (nice < 0) {
            nice = 0;
            tempStart = i + 1;  
        }
    }

    if (nicest <= 0) {
        start = -1;
        end = -1;
    }

    return nicest;
}


int maxSum(vector<vector<int>> M) {
    int maxLength = 0;

    int ROW = M.size();
    int COL = M[0].size();

    for (int left = 0; left < COL; ++left) {
        vector<int> temp(ROW, 0);

        for (int right = left; right < COL; ++right) {
            for (int i = 0; i < ROW; ++i)
                temp[i] += M[i][right];

            maxLength = max(maxLength, maxSubArray(temp, ROW));
        }
    }

    return maxLength;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> M(n, vector<int> (n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> M[i][j];
    }

    cout << maxSum(M) << endl;
    
    return EXIT_SUCCESS;
}