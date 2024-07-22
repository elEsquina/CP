#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(){
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline after reading t

    while(t--) {
        int p;
        cin >> p;
        cin.ignore(); // Ignore the newline after reading p

        vector<int> neighbourscount(p);

        for(int i = 0; i < p; i++) {
            string line;
            getline(cin, line);

            int count = 1; // Start with 1 because there's at least 1 neighbor
            for (char c : line) {
                if (c == ' ') {
                    count++;
                }
            }

            neighbourscount[i] = count;
        }

        int minCount = *min_element(neighbourscount.begin(), neighbourscount.end());

        bool first = true;
        for(int i = 0; i < p; i++) {
            if (neighbourscount[i] == minCount) {
                if (!first) {
                    cout << " ";
                }
                cout << i + 1;
                first = false;
            }
        }
        cout << endl;

        if (t) {
            string blank;
            getline(cin, blank); // Consume the blank line between test cases
        }
    }
    return 0;
}
