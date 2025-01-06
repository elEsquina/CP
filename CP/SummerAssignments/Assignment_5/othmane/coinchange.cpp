#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

int main() {
    int n; 
    
    ll coins[] = {1, 5, 10, 25, 50};
    vector<ll> memo(7490, 0);
    memo[0] = 1;
    
    for (int j = 0; j < 5; j++) {
        for (int i = coins[j]; i < 7490; i++) {
            memo[i] += memo[i - coins[j]];
        }
    } 

    while (cin >> n) {
        cout << memo[n] << endl;
    }
    return 0;
}
