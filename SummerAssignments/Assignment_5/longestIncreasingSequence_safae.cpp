#include <iostream>
#include <vector>

using namespace std;

int longestSubmatrix(vector<vector<int>> M) {
    int res = 0, h, l, r;

    for (int i = 0; i < M[0].size(); i++) {
        vector<int> sum(605, 0);
        for (int j = i; j < M[0].size(); j++) {
            h = j - i + 1;
            l = 0; r = 0;
            for (int k = 0; k < M.size(); k++) {
                if (h == 1)
                    sum[k] = 1;
                else if (M[k][j] > M[k][j-1])
                    sum[k]++;
                r = k;
                if (r-1 >= l && M[r-1][j] >= M[r][i])
                    l = max(l, k);
                if (sum[k] != h)
                    l = max(l, k+1);
                res = max(res, (r-l+1)*h);
            }
        }
    }
    return res;
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

        cout << longestSubmatrix(matrix) << endl;
    }
    return EXIT_SUCCESS;
}