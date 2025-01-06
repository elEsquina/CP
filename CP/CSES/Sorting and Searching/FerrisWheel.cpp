#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

typedef long long ll;
using namespace std;

int main() {
    ll n, x, p;
    cin >> n >> x;

    vector<ll> arr; 

    for (ll i = 0; i < n; i++) {
        cin >> p;
        arr.push_back(p);
    }
    sort(arr.begin(), arr.end()); 

    ll ret = 0;
    ll j = 0;
    for (ll i = n-1; i >= j; i--) {
        if (arr[i] + arr[j] <= x){
            j++;
        }
        ret += 1;
    }
    cout << ret << endl;
    return 0;
}
