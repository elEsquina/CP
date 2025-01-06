#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;

    ll s = 0;
    
    for(ll i = 5; n / i >= 1;  i *= 5)
        s += n/i;

    cout << s;
    return 0;
}