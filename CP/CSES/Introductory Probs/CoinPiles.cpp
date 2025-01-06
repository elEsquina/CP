#include <iostream>
using namespace std;
typedef long long ll;
int main(){
    ll t;
    ll l, r;
    cin >> t;
    for (ll i = 0; i < t; i++){
        cin >> l; cin >> r;
        cout << ( ( (2*r - l)%3 == 0 && (2*l - r)%3 == 0 &&  min(l, r) * 2 >= max(l, r) ) ? "YES" : "NO" ) << endl;
    }
    return 0;
}

