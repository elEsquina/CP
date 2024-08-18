#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(const vector<int>& prices, const vector<int>& weights, const vector<int>& caps) {
    int n = prices.size();
    int m = caps.size();
    
    int max_cap = *max_element(caps.begin(), caps.end());
    
    vector<vector<vector<int>>> K(n + 1, vector<vector<int>>(m, vector<int>(max_cap + 1, 0)));
    
    for (int i = 0; i <= n; i++) {
        for (int c = 0; c < m; c++) {
            for (int w = 0; w <= caps[c]; w++) {
                if (i == 0 || w == 0) {
                    K[i][c][w] = 0;
                } else if (weights[i-1] <= w) {
                    K[i][c][w] = max(prices[i-1] + K[i-1][c][w - weights[i-1]], K[i-1][c][w]);
                } else {
                    K[i][c][w] = K[i-1][c][w];
                }
            }
        }
    }

    int max_val = 0;
    for (int i = 0; i < m; i++) {
        max_val += K[n][i][caps[i]];
    }
    
    return max_val;
}

int main() {
    int t, n, g, max_p;

    cin >> t;

    while (t--) {
        cin >> n;
        vector<int> prices(n);
        vector<int> weights(n);
        for (int i = 0; i < n; i++) 
            cin >> prices[i] >> weights[i];
        
        cin >> g;
        vector<int> people(g);
        for (int i = 0; i < g; i++) {
            cin >> people[i];
        }

        max_p = knapsack(prices, weights, people);

        cout << max_p << endl;
    }

    return EXIT_SUCCESS;
}
