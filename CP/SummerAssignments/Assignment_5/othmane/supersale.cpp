#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll best_value(int n, const vector<ll>& weights, const vector<ll>& prices, int mw, vector<vector<ll>>& memo) {
    if (n == 0 || mw == 0) {
        return 0;
    }
    
    if (memo[n][mw] != -1) {
        return memo[n][mw];
    }

    ll result = best_value(n - 1, weights, prices, mw, memo);

    if (weights[n - 1] <= mw) {
        result = max(result, prices[n - 1] + best_value(n - 1, weights, prices, mw - weights[n - 1], memo));
    }

    memo[n][mw] = result;
    return result;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<ll> prices(N), weights(N);
        for (int i = 0; i < N; ++i) {
            cin >> prices[i] >> weights[i];
        }

        int G;
        cin >> G;
        vector<int> capacities(G);
        for (int i = 0; i < G; ++i) {
            cin >> capacities[i];
        }

        ll total_value = 0;

        for (int i = 0; i < G; ++i) {
            int capacity = capacities[i];
            vector<vector<ll>> memo(N + 1, vector<ll>(capacity + 1, -1));
            total_value += best_value(N, weights, prices, capacity, memo);
        }

        cout << total_value << endl;
    }

    return 0;
}
