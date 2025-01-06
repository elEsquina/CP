#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

typedef long long ll;
using namespace std;


int main(){
    ll n, p;
    cin >> n;

    vector<ll> inp; 
    for (ll i = 0; i < n ; i++){
        cin >> p;
        inp.push_back(p);
    }
    sort(inp.begin(), inp.end());

    ll sum = 0;
    for (ll i = 0; i < n ; i++){
        if (inp[i] > sum + 1){
            cout << sum + 1 << endl;
            return 0;
        }     
        sum += inp[i];
        
    }    

    cout << sum + 1 << endl;
    return 0;
}