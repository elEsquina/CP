#include <iostream>
using namespace std;
typedef long long ll;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main(){
    ll n;
    cin >> n;
    cout << binpow(2, n, 1e9 + 7);
    return 0;
}