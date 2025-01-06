#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
 
typedef long long ll;
using namespace std;
 
int main(){
    ll t, N, temp;
    cin >> t;
 

 
    while (t--){
        cin >> N;
            vector<pair<ll, ll>> inp; 
    ll steps, prev, cste;
        for (int i = 0; i < N; i++){
            cin >> temp;
            inp.push_back({temp, i});
        }
        if (N == 1){
            cout << 0 << endl;
            continue;
        }
        sort(inp.begin(), inp.end());
 
        steps = inp[0].second;
        prev = inp[0].second;
        for(int i = 1; i < N; i++){
            cste = 0;
            if (inp[i].second - prev < 0){
                cste = N - prev + inp[i].second; 
            }
            else{ cste = abs(inp[i].second - prev);} 
            steps += cste;
            prev = inp[i].second;
        }
 
        cout << steps << endl;
 
    }
    
    return 0;
}