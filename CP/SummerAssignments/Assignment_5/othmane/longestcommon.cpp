#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    string s1, s2;
   
    while (cin >> s1 && cin >> s2) {
        ll n = s1.size(), m = s2.size();

        vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));

        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= m; j++) {
                if (s1[i-1] == s2[j-1])  
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        cout << dp[n][m] << endl;
    }

    return 0;
}
