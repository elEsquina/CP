#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

typedef long long ll;
using namespace std;

ll height(ll base, ll N){
    ll ba = base;
    
    ll res  = 0;
    ll basis = N;

    while(basis > 0){
        basis -= ba*ba;
        ba -= 1;
        res += 1;
    }

    return res;
}

int main(){

    while (true){
        ll P, H, N; 
        cin >> P; cin >> H, cin >> N;
        
        if( P == 0 && H == 0 && N == 0 ) break;

        ll i = 0;
        while(true){
            if ( i*(i + 1)*(2*i + 1) >= N*6 && height(i, N)*P <= H ){
                cout << i << endl;
                break;
            }
            i += 1;
        }
    }
}
