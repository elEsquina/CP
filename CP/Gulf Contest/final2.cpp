#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#include <queue>
#include <utility>

typedef long long ll;
using namespace std;

ll findMaxMinDistance(vector<ll>& desks, ll students) {
    ll left = 0, right = desks.back() - desks.front();
    ll maxMinDistance = 0;

    while (left <= right) {
        ll mid = left + (right - left) / 2;
        ll studentsPlaced = 1;
        ll lastPlacedDesk = desks[0];

        for (size_t i = 1; i < desks.size(); ++i) {
            if (desks[i] - lastPlacedDesk >= mid) {
                studentsPlaced++;
                lastPlacedDesk = desks[i];
            }
        }

        if (studentsPlaced >= students) {
            maxMinDistance = max(maxMinDistance, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return maxMinDistance;
}

int main() {
    ll T;
    cin >> T;

    while (T--) {
        ll d, s, di;
        vector<ll> desks;

        cin >> d >> s;

        for (int i = 0; i < d; i++) {
            cin >> di;
            desks.push_back(di);
        }
        sort(desks.begin(), desks.end());

        ll maxMinDistance = findMaxMinDistance(desks, s);

        cout << maxMinDistance << endl;
    }

    return 0;
}
