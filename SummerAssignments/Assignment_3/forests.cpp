#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int t, p, j, pi, tj;
    string input, s;

    cin >> t;
    cin.ignore(); 

    while (t--) {
        cin >> p >> j;

        vector<set<int>> sets(p+1, set<int>{0});
        set<set<int>> opinions;

        cin.ignore();
        while (true) {
            getline(cin, input);
            if (input.empty()) {
                break;
            }
            istringstream iss(input);
            iss >> pi >> tj;
            sets[pi].insert(tj);
        }

        for (int i = 1; i <= p; i++) {
            opinions.insert(sets[i]);
        }

        s = t != 0? "\n\n" : "\n";
        cout << opinions.size() << s;
    }
    
    return EXIT_SUCCESS;
}