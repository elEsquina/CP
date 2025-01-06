#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;


int main(){
    ll n, m; 
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        
        vector<vector <ll>> matrix(n, vector<ll>(m, 0));
        vector<vector<ll>> dp(n, vector<ll>(m, 1));

        for (ll i = 0; i < n; i++){
            for (ll j = 0; j < m; j++){
                cin >> matrix[i][j];
            }
        }

        ll maxLength = 1; 

        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                if (i > 0 && matrix[i][j] > matrix[i-1][j]) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j] + 1);
                }
                if (j > 0 && matrix[i][j] > matrix[i][j-1]) {
                    dp[i][j] = max(dp[i][j], dp[i][j-1] + 1);
                }
                maxLength = max(maxLength, dp[i][j]);
            }
        }

        cout << maxLength << endl;
    }



    return 0;
}
