#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cout << (k ^ (k >> 1)) << endl;
    }
    return 0;
}