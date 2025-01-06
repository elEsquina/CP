#include <iostream>
#include <string>
using namespace std;

typedef long long ll;
ll arr[19];

void solve(ll k){

    int i = 1;
    while (k - 9*arr[i-1]*i > 0){
        k -= 9*arr[i-1]*i;
        i++;
    }
    ll number = arr[i-1] + (k - 1) / i;
    int index = (k - 1) % i;
    cout << to_string(number)[index] << endl;;
}

int main() {
    int q; 
    ll k; 
    cin >> q;

    arr[0] = 1;
    for (int i = 1; i < 19; i++){
        arr[i] = arr[i-1] * 10;
    }

    while (q--){
        cin >> k; 
        solve(k);
    }

    return 0;
}
