#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, n, cover;
    vector<char> field;
    cin >> t;

    for (int l = 1; l <= t; l++) {
        cin >> n;
        field = vector<char>(n);
        cover = 0;
        for (int i = 0; i < n; i++) {
            cin >> field[i];
        }

        for (int i = 0; i < n; i++) {
            if (field[i] == '#')
                continue;
            if (i+1 < n && (field[i+1] == '.' || (i+2 < n && field[i+2] == '.'))) {
                i += 2;
            }
            cover++;
        }

        cout << "Case " << l << ": " << cover << endl;
    }
    return EXIT_SUCCESS;
}