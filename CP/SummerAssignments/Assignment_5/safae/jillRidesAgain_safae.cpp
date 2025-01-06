#include <iostream>
#include <vector>

using namespace std;

pair<int, int> maxSubArray(vector<int> routes, int n) {
    int nicest = -1;  
    int nice = 0;
    int start = 1, end = 1, tempStart = 1;
    
    for (int i = 1; i <= n; i++) {  
        nice += routes[i];

        if (nice > nicest || (nice == nicest && (i - tempStart > end - start))) {
            nicest = nice;
            start = tempStart;  
            end = i;            
        }

        if (nice < 0) {
            nice = 0;
            tempStart = i + 1;  
        }
    }

    if (nicest <= 0) {
        start = -1;
        end = -1;
    }

    return make_pair(start, end);
}

int main() {
    int b, s, n, r;

    cin >> b;

    r = 0;
    while (b--) {
        r++;
        cin >> s;
        vector<int> routes(s);

        for (int i = 1; i < s; i++) {
            cin >> routes[i];
        }

        pair<int, int> road = maxSubArray(routes, s - 1);

        if (road.first == -1) {
            cout << "Route " << r << " has no nice parts" << endl;
        } else {
            cout << "The nicest part of route " << r << " is between stops " 
                 << road.first << " and " << road.second + 1 << endl;
        }
    }

    return EXIT_SUCCESS;
}
