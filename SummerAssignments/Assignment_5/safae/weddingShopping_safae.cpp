#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void maxSumUnderBudget(vector<vector<int>>& garments, int budget) {
    vector<vector<int>> dp(garments.size(), vector<int>(budget + 1, -1));

    for (int price: garments[0]) {
        if (price <= budget) {
            dp[0][budget - price] = price;
        }
    }

    for (int i = 1; i < garments.size(); i++) {
        for (int b = 0; b <= budget; b++) {
            if (dp[i-1][b] == -1)
                continue;

            for (int price: garments[i]) {
                if (price <= b)
                    dp[i][b-price] = max(dp[i-1][b], dp[i][b-price]);
            }
        }
    }

    int result = -1;
    for (int b = 0; b <= budget; b++) {
        if (dp[garments.size()-1][b] != -1) 
            result = max(result, budget - b);
    }

    if (result != -1)
        cout << result << endl;
    else
        cout << "no solution" << endl;
}

int main() {
    int n, m, c, k;
    const int max_k = 20;
    cin >> n;

    while (n--) {
        cin >> m >> c;
        vector<vector<int>> garments(c);

        for (int i = 0; i < c; i++) {
            cin >> k;
            garments[i].resize(k);
            for (int j = 0; j < k; j++) {
                cin >> garments[i][j];
            }
        }

        maxSumUnderBudget(garments, m);
    }

    return EXIT_SUCCESS;
}
