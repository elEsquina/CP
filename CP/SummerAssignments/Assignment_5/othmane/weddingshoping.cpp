#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll get_maximum_value(vector<vector<ll>> prices, ll money){
    vector<vector<ll>> dp(money + 1, vector<ll>(prices.size(), 0));
    
    for (ll i = 0; i <= money; i++){

        for (ll j = 0; j < prices.size(); j++){
            for (ll k = 0; k < prices[j].size(); k++){
                if (i - prices[j][k] >= 0){

                    if (j == 0){
                        dp[i][j] = max(dp[i][j], prices[j][k]);
                    } else {
                        dp[i][j] = max(dp[i][j], prices[j][k] + dp[i - prices[j][k]][j - 1]);
                    }

                }
            }
        }
    }

    return dp[money][prices.size() - 1];
}

int main(){
    ll n, m, c, k, temp_x, out;
    cin >> n; 
    
    while(n--){
        cin >> m >> c;

        vector<vector<ll>> prices;
        out = 0;

        for(int i = 0; i < c; i++){
            vector<ll> temp;

            cin >> k;
            for(int j = 0; j < k; j++){
                cin >> temp_x;
                temp.push_back(temp_x);
            }

            out += *min_element(temp.begin(), temp.end());
            prices.push_back(temp);
        }

        if (out > m){
            cout << "no solution" << endl;
        } else {
            cout << get_maximum_value(prices, m) << endl;
        }

    }
    return 0;
}



