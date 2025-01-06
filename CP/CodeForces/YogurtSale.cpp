#include <iostream>
typedef long long ll;
using namespace std;

int main(){
    ll t, a, n, b; 
    cin >> t;

    while (t--){
        
        cin >> n;
        cin >> a;
        cin >> b;

        if (a > b){
            cout << n * a;
        }
        else{
            cout << n/2 * b + a * (n%2);
        }

    }
}