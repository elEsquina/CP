#include <iostream>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin >> n;
    ll sum  = n*(n + 1)/4;
    
    if ( n *(n + 1) % 4 != 0){
        cout << "NO";
        return 0;
    }

    cout << "YES" << endl;
    ll p = 0;
    ll c = 0;
    ll arr_p[n];
    ll arr_c[n];
    for (ll i = n; i > 0; i--){
        if (sum >= i){
            arr_p[p] = i;
            p++;
            sum -= i; 
        }
        else{
            arr_c[c] = i;
            c++;
        }
    }

    cout << p << endl;
    for (ll i = 0; i < p; i++){
        cout << arr_p[i] << " ";
    }

    cout << endl << c << endl;
    for (ll i = 0; i < c; i++){
        cout << arr_c[i] << " ";
    }

}