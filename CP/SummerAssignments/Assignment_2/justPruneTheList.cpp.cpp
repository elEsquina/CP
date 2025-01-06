#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int t, n, m, a, diff;

    cin >> t;

    while (t--) {
        cin >> n >> m;
        unordered_map<int, int> l1;
        unordered_map<int, int> l2;
        diff = 0;
        while (n--) {
            cin >> a;
            l1[a]++;
        }
        while (m--) {
            cin >> a;
            l2[a]++;
        }

        for(auto i: l1) {
            diff += abs(i.second - l2[i.first]);
            l2.erase(i.first);
        }

        for (auto i: l2) {
            diff += abs(i.second);
        }

        cout << diff << endl;
    }

    return EXIT_SUCCESS;
}
