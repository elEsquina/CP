#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

pair<ll, ll> nice(const vector<ll>& routes, ll n) {
    ll maxSum = -1;
    ll currentSum = 0;
    ll start = 0, end = 0, tempStart = 0;

    for (ll i = 0; i < n; i++) {
        currentSum += routes[i];

        if (currentSum > maxSum || (currentSum == maxSum && i - tempStart > end - start)) {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }

        if (currentSum < 0) {
            currentSum = 0;
            tempStart = i + 1;
        }
    }

    if (maxSum <= 0) {
        return {-1, -1}; 
    }

    return {start + 1, end + 1};  
}

int main() {
    ll testCases;
    cin >> testCases;

    for (ll r = 1; r <= testCases; r++) {
        ll stops;
        cin >> stops;
        vector<ll> routes(stops - 1);

        for (ll i = 0; i < stops - 1; i++) {
            cin >> routes[i];
        }

        pair<ll, ll> nicestSegment = nice(routes, stops - 1);

        if (nicestSegment.first == -1) {
            cout << "Route " << r << " has no nice parts" << endl;
        } else {
            cout << "The nicest part of route " << r << " is between stops " 
                 << nicestSegment.first << " and " << nicestSegment.second << endl;
        }
    }

    return 0;
}
