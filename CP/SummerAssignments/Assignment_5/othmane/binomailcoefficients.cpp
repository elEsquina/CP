#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
typedef long long ll;

void reverse_binomial_coefficient(ll big, const vector<ll>& inputs, vector<set<pair<ll, ll>>>& dp) {
    vector<vector<ll>> memo(big + 1, vector<ll>(big + 1, 0));
    memo[0][0] = 1;

    for (ll i = 1; i <= big; i++) {
        memo[i][0] = 1;
        memo[i][i] = 1;
        for (ll j = 1; j < i; j++) {
            memo[i][j] = memo[i - 1][j - 1] + memo[i - 1][j];

            // Check if memo[i][j] exceeds 'big', if yes, skip further processing
            if (memo[i][j] > big) {
                break;
            }

            for (ll k = 0; k < inputs.size(); k++) {
                if (memo[i][j] == inputs[k]) {
                    dp[k].insert(make_pair(i, j)); // Append the pair (i, j) to dp[k]
                    dp[k].insert(make_pair(i, i - j)); // Append the pair (i, i - j) to dp[k]
                }
            }
        }
    }
}

int main() {
    ll t, m, maxi = 0;

    vector<ll> inputs;
    cin >> t;

    while (t--) {
        cin >> m;
        inputs.push_back(m);
        if (m > maxi) maxi = m;
    }

    // Initialize dp with the size of inputs
    vector<set<pair<ll, ll>>> dp(inputs.size());

    reverse_binomial_coefficient(maxi, inputs, dp);

    for (ll i = 0; i < inputs.size(); i++) {
        //sort(dp[i].begin(), dp[i].end());
        cout << dp[i].size() << endl;
        for (const auto& p : dp[i]) {
            cout << "(" << p.first << "," << p.second << ") ";
        }
        cout << endl;
    }

    return 0;
}
