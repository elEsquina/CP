#include <iostream>

typedef long long ll;
using namespace std;

int main(){
    ll x, out;
    cin >> x; 

    // BRIAN KERNIGHAN'S ALGORITHM
    out = 0;
    while (x){
        x = x & (x-1);
        out++;
    }

    cout << out;
    return 0;
}