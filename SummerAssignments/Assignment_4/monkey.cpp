#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
typedef long long ll;

bool verify(const vector<ll>& keys, const map<ll, ll>& diff, ll k) {
    for (auto el : keys) {
        if (k < el) {
            return false;
        } 
        else if (k == el) {
            if (k - diff.at(el) + 1 >= el) {
                k = k - diff.at(el);
            } else {
                return false;
            }
        }
        else{
            return true ; 
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    int test_case = 1;
    while (t--) {
        ll n;
        cin >> n;

        vector<ll> rungs(n);
        for (int i = 0; i < n; i++) {
            cin >> rungs[i];
        }

        map<ll, ll> diff;
        set<ll> keys;
        diff[rungs[0]] = 1 ;
        keys.insert(rungs[0]) ; 
        // Calculate differences between consecutive rungs
        for (int i = 1; i < n; i++) {
            ll difference = rungs[i] - rungs[i - 1];
            if (diff.find(difference) != diff.end()) {
                diff[difference] += 1;
            } else {
                diff[difference] = 1;
                keys.insert(difference);
            }
        }

        // Reverse keys (since keys are stored in a set, put them into a vector first)
        vector<ll> reversedKeys(keys.begin(), keys.end());
        reverse(reversedKeys.begin(), reversedKeys.end());

        ll k = reversedKeys[0];
        
        // Ensure the smallest valid k is found
        if (diff[k] != 1) {
            k += 1;
        } else {
            if (!verify(reversedKeys, diff, k)) {
                k += 1;
            }
        }

        // Output the result for the current test case
        cout << "Case " << test_case << ": " << k << endl;

        test_case += 1;
    }

    return 0;
}
