#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll T, n, temp;
    cin >> T;

    while(T--){
        cin >> n;
        vector<ll> v;
        ll DP[n][n];

        for (ll i = 0; i < n; i++){
            cin >> temp;
            v.push_back(temp);
        }

        for (ll i = 0; i < n; i++){
            for (ll j = 0; j < n; j++){
                DP[i][j] = LONG_MIN;
            }

            DP[i][i] = v[i];
        }

        for (ll i = 0; i < n; i++){
            for (ll j = i+1; j < n; j++){
                ll max1 = max(DP[i-1][j], DP[i][j-1]);
                DP[i][j] = max(v[i] - v[j], max1);
            }
        }

        cout << DP[n-1][n-1] << endl;
    }


    return 0;
}